#version 130

in vec3 fN,fL,fV;

out vec4 fragColor;

uniform vec3 materialDiffuse,materialSpecular;
uniform vec4 materialAmbient;

void main() {
    float diffuseIntensity;
    float specularIntensity=0;
    vec3 L,V,N,R;
    vec4 color=vec4(0,0,0,0);

    V=normalize(fV);
    L=normalize(fL);
    N=normalize(fN);

    R=normalize(R);
    R=2*(dot(L,N))*N-L;

    // notez le max pour ne pas éclairer lorsque le produit scalaire est négatif (il faudra faire la même chose lors du calcul du spéculaire)
    diffuseIntensity=max(dot(N,L),0.0);
    specularIntensity=pow(max(dot(V,R),0.0),50.0);

    // rouge, vert,bleu de l'éclairement :
    color.rgb=diffuseIntensity*materialDiffuse+materialAmbient.xyz;
    color.rgb=color.rgb + materialSpecular*specularIntensity; //q2

    // le alpha est porté uniquement par materialAmbient.a.:
    color.a=materialAmbient.a;
    fragColor=color;
}

