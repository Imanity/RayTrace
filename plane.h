#ifndef PLANE_H
#define PLANE_H

#include "geometry.h"
#include "ray.h"
#include "utility.h"

class Plane : public Geometry {
public:
    Vec3 normal;
    double d;
    Vec3 pos;

public:
    Plane();
    Plane(Vec3 v, double d_);

    IntersectResult intersect(Ray r);
};

#endif // PLANE_H
