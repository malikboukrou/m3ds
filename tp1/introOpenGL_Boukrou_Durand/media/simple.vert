#version 130
        
in vec3 position;
in vec4 color;

out vec4 fcolor;
        
void main() {
    fcolor = color;
    gl_Position=vec4(position,1.0);
}
