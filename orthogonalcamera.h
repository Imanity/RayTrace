#ifndef ORTHOGONALCAMERA_H
#define ORTHOGONALCAMERA_H

#include "vec3.h"
#include "ray.h"

#define M_PI 3.1416

class OrthogonalCamera {
public:
    Vec3 eye;
    Vec3 forward, up;
    Vec3 vx, vy, vz;
    double width, height;

public:
    OrthogonalCamera();
    OrthogonalCamera(Vec3 e, Vec3 f, Vec3 u, double w, double h);
    void initV();

    Ray generateRay(double x, double y);
};

#endif // ORTHOGONALCAMERA_H
