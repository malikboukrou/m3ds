#version 130

in vec3 position; // Eye Coordinates
in vec3 normal;
out vec3 fColor;
uniform mat4 projection;
uniform mat4 transform;

uniform vec3 lightposition;
uniform vec3 diffuseColor;

void main() {
    vec3 N = normal;
    vec3 L = lightposition - position;

    N = normalize(N);
    L = normalize(L);

    float intensity = max(dot(N,L),0.0);

    vec4 eyePosition=vec4(position,1);
    vec4 clipPosition=projection*transform*eyePosition;

    //fColor=normal;
    //fColor = vec3(intensity, intensity, intensity);
    fColor = intensity*diffuseColor;

    gl_Position=clipPosition;

}
