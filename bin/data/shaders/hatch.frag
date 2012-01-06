uniform sampler2DRect Tex0;

/*
 * http://jmonkeyengine.org/groups/user-code-projects/forum/topic/crosshatch-post-processing-filter-lets-go-manga/
 * Sets color influence of original image on lines drawn
 * uniform float m_ColorInfluenceLine

 * Sets color influence of original image on non-line areas
 * uniform float m_ColorInfluencePaper

 * Sets line/paper color ratio for areas with values < luminance5, really dark areas get no lines but a filled blob instead
 * uniform float m_FillValue;

 * Sets minimum luminance levels for lines drawn
 * float m_Luminance1: Top-left to down right 1
 * float m_Luminance2: Top-right to bottom left 1
 * float m_Luminance3: Top-left to down right 2
 * float m_Luminance4: Top-right to bottom left 2
 * float m_Luminance5: Blobs
 */ 


uniform	float m_ColorInfluenceLine;
uniform	float m_ColorInfluencePaper;
uniform	float m_FillValue;
uniform	float m_Luminance1;
uniform	float m_Luminance2;
uniform	float m_Luminance3;
uniform	float m_Luminance4;
uniform	float m_Luminance5;
uniform	float m_LineDistance;
uniform	float m_LineThickness;
 
void main() {
	vec4 m_LineColor = vec4(0.2, 0.2, 0.2, 0.2);
	vec4 m_PaperColor = vec4(1.0, 1.0, 1.0, 1.0);

    vec4 texVal = texture2DRect(Tex0, gl_TexCoord[0].st);
    float linePixel = 0.0;
    float lum = texVal.r*0.2126 + texVal.g*0.7152 + texVal.b*0.0722;
 
    if (lum < m_Luminance1){
        if (mod(gl_FragCoord.x + gl_FragCoord.y, m_LineDistance * 2.0) < m_LineThickness){
            linePixel = 1.0;
		}
    }
    if (lum < m_Luminance2){
        if (mod(gl_FragCoord.x - gl_FragCoord.y, m_LineDistance * 2.0) < m_LineThickness)
            linePixel = 1.0;
    }
    if (lum < m_Luminance3){
        if (mod(gl_FragCoord.x + gl_FragCoord.y - m_LineDistance, m_LineDistance) < m_LineThickness)
            linePixel = 1.0;
    }
    if (lum < m_Luminance4){
        if (mod(gl_FragCoord.x - gl_FragCoord.y - m_LineDistance, m_LineDistance) < m_LineThickness)
            linePixel = 1.0;
    }
    if (lum < m_Luminance5){ // No line, make a blob instead
        linePixel = m_FillValue;
    }
 
    // Mix line color with existing color information
    vec4 lineColor = mix(m_LineColor, texVal, m_ColorInfluenceLine);
    // Mix paper color with existing color information
    vec4 paperColor = mix(m_PaperColor, texVal, m_ColorInfluencePaper);
 
	gl_FragColor = mix(paperColor, lineColor, linePixel);
}