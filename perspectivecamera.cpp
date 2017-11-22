#include "perspectivecamera.h"

PerspectiveCamera::PerspectiveCamera() {
    eye = Vec3(0, 0, 0);
    up = Vec3(0, 0, 1);
    forward = Vec3(1, 0, 0);
    fov = 60;
    initV();
}

PerspectiveCamera::PerspectiveCamera(Vec3 e, Vec3 f, Vec3 u, double fov_) {
    eye = e;
    forward = f;
    up = u;
    fov = fov_;
    initV();
}

void PerspectiveCamera::initV() {
    up = up.normalize();
    forward = forward.normalize();
    vy = up.negate();
    vz = forward;
    vx = vy.cross(vz);
    fovScale = tan(fov * 0.5 * M_PI / 180.0) * 2;
}

Ray PerspectiveCamera::generateRay(double x, double y) {
    Vec3 x_ = vx.multiply((x - 0.5) * fovScale);
    Vec3 y_ = vy.multiply((y - 0.5) * fovScale);
    return Ray(eye, forward.add(x_).add(y_).normalize());
}
