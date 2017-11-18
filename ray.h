#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
public:
    Vec3 origin, direction;

public:
    Ray();
    Ray(Vec3 o, Vec3 d);

    Vec3 getPoint(double t);
};

#endif // RAY_H
