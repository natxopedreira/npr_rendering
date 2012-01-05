#version 120
uniform sampler2DRect Tex0; //these are our texture names, set in openFrameworks on the shader object in set up

//Bayer Ordered dithering

void main()
{
vec4 image = texture2DRect(Tex0, gl_TexCoord[0].st);
vec3 color = image.rgb;

vec3 luminosity = vec3(0.30, 0.59, 0.11);
float lum = dot(luminosity, color);

float v = gl_FragCoord.s;
float h = gl_FragCoord.t;

gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);

if (lum < 0.9)
{
gl_FragColor.rgb *= floor(((fract(v/2.0))+(fract(h/2.0)))+ 0.5);
}

if (lum < 0.75)
{
gl_FragColor.rgb *= floor((fract(v+v/2.0))+(fract(h+h/2.0)));
}

if (lum < 0.5)
{
gl_FragColor.rgb *= floor((fract(v+v+v/2.0))+(fract(h+h/2.0)));
}

if (lum < 0.25)
{
gl_FragColor.rgb *= floor(((fract(v/2.0))+(fract(h/2.0)))+ 0.5);
}

}