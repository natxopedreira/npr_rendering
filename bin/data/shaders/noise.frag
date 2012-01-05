uniform sampler2DRect Tex0; //these are our texture names, set in openFrameworks on the shader object in set up

void main()
	{
		vec4 image = texture2DRect(Tex0, gl_TexCoord[0].st);
		
	    float lum = length(image.rgb);
	     
	    gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
	     
	    if (lum < 1.00) {
	        if (mod(gl_FragCoord.x + gl_FragCoord.y, 10.0) == 0.0) {
	            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	        }
	    }
	     
	    if (lum < 0.75) {
	        if (mod(gl_FragCoord.x - gl_FragCoord.y, 10.0) == 0.0) {
	            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	        }
	    }
	     
	    if (lum < 0.50) {
	        if (mod(gl_FragCoord.x + gl_FragCoord.y - 5.0, 10.0) == 0.0) {
	            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	        }
	    }
	     
    if (lum < 0.3) {
	        if (mod(gl_FragCoord.x - gl_FragCoord.y - 5.0, 10.0) == 0.0) {
	            gl_FragColor = vec4(0.0, 0.0, 0.0, 1.0);
	        }
	    }
}