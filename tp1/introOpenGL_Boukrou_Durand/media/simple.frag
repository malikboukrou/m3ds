#version 130

out vec4 fragColor;
in vec4 fcolor;
in vec2 fTexCoord;

uniform float coeff;
uniform sampler2D texture;


void main() {
    //fragColor=texture2D(texture,fTexCoord);
    fragColor=texture2D(texture,fTexCoord)*fcolor; // fColor étant la couleur interpolée aux sommets(questions précédentes)
    // coeff = uniform passée par l'application (questions précédentes).
    fragColor.g*=(1.0-coeff);
}
