#include "plane.h"

Plane::Plane() {
    normal = Vec3(0, 0, 1);
    d = 0;
    pos = Vec3(0, 0, 0);
}

Plane::Plane(Vec3 v, double d_) {
    normal = v.normalize();
    d = d_;
    pos = normal.multiply(d).negate();
}

IntersectResult Plane::intersect(Ray r) {
    IntersectResult res;
    double a = r.direction.dot(normal);
    if (a >= 0) {
        res.type = NO_HIT;
        return res;
    }
    res.type = HIT;
    double b = normal.dot(r.origin.subtract(pos));
    res.t = abs(b / a);
    res.pos = r.getPoint(res.t);
    res.color = c;
    res.normal = normal;
    res.n = n;
    res.kd = kd;
    res.ks = ks;
    return res;
}
