#version 130

uniform sampler2D depthTexture;

in vec4 fTexCoord;

out vec4 fragColor;

void main() {
    vec4 texCoord=fTexCoord;

    texCoord.xyz/=texCoord.w; // clip coordinates => ndc
    texCoord.xyz += 1;
    texCoord.xyz /= 2;


    fragColor = texture(depthTexture,texCoord.xy);

    if (texCoord.x <= 0)
        fragColor = vec4(0.3,0,0,0);
    else fragColor = vec4(0,0,0.3,0.5);

    if(texCoord.z>=0.0){
            if(texCoord.z-0.001>texture(depthTexture,texCoord.xy).z){
                fragColor=vec4(0.3,0,0,1);
            }
            else {
                fragColor=vec4(0,0.3,0,0);
            }
        }
        else {
            fragColor=vec4(0,0,0.3,0);
        }
}

