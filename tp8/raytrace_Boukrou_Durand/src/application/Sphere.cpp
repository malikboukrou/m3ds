#include "Sphere.h"
#include <cmath>
#include <iostream>
#include "GLTool.h"
#include "IntersectionArray.h"

/**
@file
@author Fabrice Aubert
*/

using namespace p3d;
using namespace std;

Sphere::Sphere() : Primitive() {}


/**
  donne la liste croissante issus de l'intersection de ray=(A,u)  et de la sphere x^2+y^2+z^2=1
  (2 ou 0 intersection)
*/
void Sphere::intersection(const Ray &ray,IntersectionArray *result) {

  /**
   * A COMPLETER : il faut résoudre l'équation en lambda (cf cours), puis créer dans le résultat les intersections correspondantes aux lambda  :
   * !! pour ajouter une intersection à la fin de la liste result, utilisez uniquement : result->addIntersection(lambda)
   * ray est déjà dans le repère local de la sphere unitaire centrée à l'origine :
   *   - ray.point() : donne l'origine du rayon (Vector3)
   *   - ray.direction() : donne le vecteur directeur (Vector3)
   * il faut impérativement retourner 0 ou 2 intersections pour assurer une cohérence dans l'intersection.
   * il faut que les intersections soient triées (ordre croissant) pour assurer le fonctionnement avec l'algorithme général d'intersection avec le CSG
   *
   *  rappel : a.dot(b) donne le produit scalaire de a par b  : OK
   */

  result->clear(); // initialisation : liste d'intersection vide

  float a = ray.direction().dot(ray.direction());
  float b = 2.0 * ray.direction().dot(ray.point());
  float c = ray.point().dot(ray.point()) - 1;
  float d = pow(b,2) - 4 * a * c;

  if (d > 0){
      float res1 = (-b-sqrt(d))/(2*a);
      float res2 = (-b+sqrt(d))/(2*a);
      if (res1 < res2){
          result->addIntersection(res1);
          result->addIntersection(res2);
      }
      else{
          result->addIntersection(res2);
          result->addIntersection(res1);
      }
  }
}


/** ****************************************************** **/
/** ****************************************************** **/
/** ****************************************************** **/
/** ****************************************************** **/

Vector3 Sphere::computeNormal(const Vector3 &p) {
  return p;
}


void Sphere::drawGL() {
  p3d::shaderLightPhong();
  materialGL();
  p3d::drawSphere();
}

