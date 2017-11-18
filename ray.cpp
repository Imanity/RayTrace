#include "ray.h"

Ray::Ray() {
    origin = Vec3(0, 0, 0);
    direction = Vec3(1, 0, 0);
}

Ray::Ray(Vec3 o, Vec3 d) {
    origin = o;
    direction = d.normalize();
}

Vec3 Ray::getPoint(double t) {
    return origin.add(direction.multiply(t));
}
