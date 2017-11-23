#ifndef SPHERE_H
#define SPHERE_H

#include "geometry.h"
#include "chesstexture.h"

#define M_PI 3.1416

class Sphere : public Geometry {
public:
    Vec3 center;
    double radius;

    bool usingTexture = false;
    ChessTexture texture;

public:
    Sphere();
    Sphere(Vec3 c, double r);

    IntersectResult intersect(Ray r);
    void setAABB();
};

#endif // SPHERE_H
