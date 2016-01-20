#include "GLApplication.h"

#include <iostream>

using namespace std;

GLApplication::~GLApplication() {
}

GLApplication::GLApplication() {
  _trianglePosition = {
    -0.8,-0.5,0.0, // vertex 0
    -0.2,-0.5,0.0, // 1
    -0.5,0.5,0.0,  // 2

    0.2,0.5,0.0,  // 3
    0.8,0.5,0.0,  // 4
    0.5,-0.5,0.0  // 5
  };

  _triangleColor = {
    0.3,0,0.6,1,
    0.3,0,0.6,1,
    0.0,0.9,0.0,1,

    0.0,0.5,0.6,1,
    0.0,0.5,0.6,1,
    0.9,0.0,0.0,1
  };




}




/** ********************************************************************** **/
void GLApplication::initialize() {
  // appelée 1 seule fois à l'initialisation du contexte
  // => initialisations OpenGL
  glClearColor(1,1,1,1);

  glLineWidth(2.0);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


  _shader0=initProgram("simple");


  initTriangleBuffer();
  initTriangleVAO();
  initTexture();


}

void GLApplication::resize(int width,int height) {
  // appelée à chaque dimensionnement du widget OpenGL
  // (inclus l'ouverture de la fenêtre)
  // => réglages liés à la taille de la fenêtre
  glViewport(0,0,width,height);
  // ...
}

void GLApplication::update() {
  // appelée toutes les 20ms (60Hz)
  // => mettre à jour les données de l'application
  // avant l'affichage de la prochaine image (animation)
  // ...


}

void GLApplication::draw() {
  // appelée après chaque update
  // => tracer toute l'image
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(_shader0);
  glBindVertexArray(_triangleVAO);

  glDrawArrays(GL_TRIANGLES,0,3);

  glBindVertexArray(0);
  glUseProgram(0);


  snapshot(); // capture opengl window if requested
}

/** ********************************************************************** **/
/** i = button number, s = button text
 */
void GLApplication::leftPanel(int i,const std::string &s) {
  cout << "GLApplication : button clicked " << i << " " << s << endl;
  /*
  switch (i) {
    case 0:menu0();break;
    case 1:menu1();break;
  }
  */
}




/** *********************************************************** **/
GLuint GLApplication::initProgram(const std::string &filename) {
  GLuint program;
  int infoLength; // for message error

  string vertexSource=p3d::readTextFile(filename+".vert");
  string fragmentSource=p3d::readTextFile(filename+".frag");

  program=glCreateProgram();
  GLuint vertexShader=glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
  glAttachShader(program,vertexShader);
  glAttachShader(program,fragmentShader);

  const char *source;
  source=vertexSource.c_str();
  glShaderSource(vertexShader,1,&source,NULL);
  source=fragmentSource.c_str();
  glShaderSource(fragmentShader,1,&source,NULL);

  GLint ok;
  glCompileShader(vertexShader);
  glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&ok);
  if (!ok) {
    glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&infoLength);
    cout << "=============================" << endl;
    cout << "GLSL Error : " << endl;
    char *info=new char[infoLength];
    glGetShaderInfoLog(vertexShader,infoLength,NULL,info);
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Vertex Shader compilation error");
  }

  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&ok);
  if (!ok) {
    glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&infoLength);
    cout << "=============================" << endl;
    cout << "GLSL Error : " << endl;
    char *info=new char[infoLength];
    glGetShaderInfoLog(fragmentShader,infoLength,NULL,info);
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Vertex Shader compilation error");
  }

  glBindAttribLocation(program,0,"position");



  glLinkProgram(program);
  glGetProgramiv(program,GL_LINK_STATUS,&ok);
  if (!ok) {
    char *info=new char[infoLength];
    glGetProgramInfoLog(program,infoLength,NULL,info);
    cout << "Info Log :" << endl;
    cout << info;
    cout << endl;
    delete info;
    throw ErrorD("Program Shader : link error (varyings ok ?)");
  }

  return program;
}


void GLApplication::initTexture() {
    QImage img;
    img.load("../media/lagoon.jpg");
    img=img.convertToFormat(QImage::Format_ARGB32).mirrored();

    glGenTextures(1,&_textureId);
    glBindTexture(GL_TEXTURE_2D,_textureId);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,img.width(),img.height(),0,GL_BGRA,GL_UNSIGNED_BYTE,img.bits());



    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
}


void GLApplication::initTriangleBuffer() {

  glGenBuffers(1,&_trianglePositionBuffer);
  glBindBuffer(GL_ARRAY_BUFFER,_trianglePositionBuffer);
  glBufferData(GL_ARRAY_BUFFER,_trianglePosition.size()*sizeof(float),_trianglePosition.data(),GL_STATIC_DRAW);



}


void GLApplication::initTriangleVAO() {
  glGenVertexArrays(1,&_triangleVAO);
  glBindVertexArray(_triangleVAO);

  glBindBuffer(GL_ARRAY_BUFFER,_trianglePositionBuffer);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);



  glEnableVertexAttribArray(0);


  glBindVertexArray(0);
}



