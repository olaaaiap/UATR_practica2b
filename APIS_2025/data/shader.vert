#version 330   
uniform mat4 mMat;    

in vec4 vPos;  
in vec4 vColor;

out vec4 fColor; 

void main()  
{  
	gl_Position=mMat*vPos;  
	fColor = vColor; //pasamos el color al siguiente shader
} 