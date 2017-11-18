#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "vec3.h"
#include "ray.h"

#define M_PI 3.1416

class PerspectiveCamera {
public:
    Vec3 eye;
    Vec3 forward, up;
    Vec3 vx, vy, vz;
    double fov;
    double fovScale;

public:
    PerspectiveCamera();
    PerspectiveCamera(Vec3 e, Vec3 f, Vec3 u, double fov_);
    void initV();

    Ray generateRay(double x, double y);
};

#endif // PERSPECTIVECAMERA_H
