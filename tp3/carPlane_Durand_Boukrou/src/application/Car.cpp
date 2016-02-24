#include <math.h>
#include "Car.h"
#include "GLTool.h"
#include "GLRender.h"

using namespace p3d;
using namespace std;


// ************************************************************
Car::~Car() {
}

Car::Car() {
  _orientation.setIdentity();
  _position.set(0,0,0);
  _steering=0;
  _rotateWheel=0;
  _acceleration=0;
  _velocity=0;
}

// ******************************************************************
// méthodes à compléter lors du TP
void Car::drawRim() {

    p3d::modelviewMatrix.push();
    p3d::diffuseColor=Vector3(1,1,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(45,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(90,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(135,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(180,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(225,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(270,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(315,1,0,0);
    p3d::modelviewMatrix.scale(0.1,0.1,2);
    drawCylinder();
    p3d::modelviewMatrix.pop();
}

void Car::drawWheel() {

    p3d::modelviewMatrix.push();

    p3d::modelviewMatrix.scale(2.5,2.5,2.5);
    p3d::modelviewMatrix.rotate(90,0,1,0);
    p3d::diffuseColor=Vector3(0,1,0);
    drawTorus();

    p3d::modelviewMatrix.pop();
}

void Car::drawAxle() {
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.translate(-2.5,0,0);
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.rotate(90,0,1,0);
    p3d::modelviewMatrix.scale(0.3,0.3,5);
    p3d::diffuseColor=Vector3(1,0,0);
    drawCylinder();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    drawRim();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    drawWheel();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.translate(5,0,0);
    drawRim();
    drawWheel();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.pop();
}

void Car::drawBody() {
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.scale(6,2,2);
    p3d::diffuseColor=Vector3(0,0.3,0.8);
    p3d::modelviewMatrix.translate(-0.75,1.1,1.25);
    drawCube();
    p3d::modelviewMatrix.pop();
    p3d::modelviewMatrix.push();
    p3d::modelviewMatrix.scale(2,2,2);
    p3d::modelviewMatrix.translate(0.5,3.1,0);
    p3d::modelviewMatrix.translate(-0.75,0,1.25);
    drawCube();
    p3d::modelviewMatrix.pop();
}

void Car::draw() {
  p3d::modelviewMatrix.scale(0.6,0.6,0.6);
  p3d::modelviewMatrix.translate(0,-2.5,0);
  p3d::modelviewMatrix.push();
  p3d::modelviewMatrix.translate(0,0,1);
  p3d::modelviewMatrix.rotate(_rotateWheel,1,0,0);
  drawAxle();
  p3d::modelviewMatrix.pop();
  p3d::modelviewMatrix.push();
  p3d::modelviewMatrix.translate(0,0,9.5);
  p3d::modelviewMatrix.rotate(_steering,0,1,0);
  p3d::modelviewMatrix.rotate(_rotateWheel,1,0,0);
  drawAxle();
  p3d::modelviewMatrix.pop();
  p3d::modelviewMatrix.push();
  p3d::modelviewMatrix.rotate(90,0,1,0);
  p3d::modelviewMatrix.translate(0,0,-2.5);
  drawBody();
  p3d::modelviewMatrix.pop();
}


void Car::drawWorld() {

  p3d::modelviewMatrix.push();
  p3d::modelviewMatrix.rotate(_orientation);
  p3d::modelviewMatrix.translate(_position);
  draw(); // tracé de la voiture dans son repère local
  p3d::modelviewMatrix.pop();
}

void Car::move() {
  const double speedLimit = 0.5;
  _acceleration+=-_velocity/50;
  _velocity+=_acceleration;
  _rotateWheel+=_velocity*10;
  _steering-=_steering/10*fabs(_velocity);

  p3d::Vector3 _uneDirection;
  _uneDirection.set(0, 0, _velocity);
  _uneDirection *= speedLimit;
  _position = _position+_uneDirection;

  _orientation.rotate(_steering*_velocity/(1.0+fabs(_velocity)),Vector3(0,1,0)); // le /(1.0+fabs(_velocity)) a été déterminé empiriquement

}


void Car::accelerate() {
  _acceleration=0.05;

}

void Car::decelerate() {
  _acceleration=0;
}

void Car::brake() {
  _acceleration=-0.02;

}

void Car::turnLeft() {
  _steering+=0.5;
  if (_steering>35) _steering=35;
}

void Car::turnRight() {
  _steering-=0.5;
  if (_steering<-35) _steering=-35;
}





