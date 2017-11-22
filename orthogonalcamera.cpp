#include "orthogonalcamera.h"

OrthogonalCamera::OrthogonalCamera(){
    eye = Vec3(0, 0, 0);
    up = Vec3(0, 0, 1);
    forward = Vec3(1, 0, 0);
    width = height = 16;
    initV();
}

OrthogonalCamera::OrthogonalCamera(Vec3 e, Vec3 f, Vec3 u, double w, double h) {
    eye = e;
    forward = f;
    up = u;
    width = w;
    height = h;
    initV();
}

void OrthogonalCamera::initV() {
    up = up.normalize();
    forward = forward.normalize();
    vy = up.negate();
    vz = forward;
    vx = vy.cross(vz);
}

Ray OrthogonalCamera::generateRay(double x, double y) {
    Vec3 x_ = vx.multiply((x - 0.5) * width);
    Vec3 y_ = vy.multiply((y - 0.5) * height);
    return Ray(eye.add(x_).add(y_), forward);
}
