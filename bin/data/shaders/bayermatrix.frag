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

float muti = 0.0;
float parte = fract(v/2)+fract(h/2);
float otra = floor(parte);

float parte2 = fract(v+v/2)+fract(h+h/2);
float otra2 = floor(parte2);

float parte4 = fract(v+v+v/2)+fract(h+h/2);
float otra4 = floor(parte4);

float parte6 = fract(v+v/2)+fract(h+h+h/2);
float otra6 = floor(parte6);


if (lum < 0.9)
{
gl_FragColor.rgb *= otra;
}

if (lum < 0.75)
{
	gl_FragColor.rgb *= otra2;
}

if (lum < 0.5)
{
gl_FragColor.rgb *= otra4;
}

if (lum < 0.25)
{
gl_FragColor.rgb *= otra6;
}

}