#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class Vec3 {
public:
    double x, y, z;

public:
    Vec3();
    Vec3(double x_, double y_, double z_);

    double length();
    Vec3 normalize();
    Vec3 negate();

    Vec3 add(Vec3 v);
    Vec3 subtract(Vec3 v);
    Vec3 multiply(double r);
    Vec3 divide(double r);

    double dot(Vec3 v);
    Vec3 cross(Vec3 v);
};

#endif // VEC3_H
