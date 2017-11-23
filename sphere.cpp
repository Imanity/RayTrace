#include "sphere.h"
#include <QDebug>

Sphere::Sphere() {
    center = Vec3(0, 0, 0);
    radius = 1;
}

Sphere::Sphere(Vec3 c, double r) {
    center = c;
    radius = r;
}

IntersectResult Sphere::intersect(Ray r) {
    IntersectResult res;
    double b_ = 2 * (r.direction.x * (r.origin.x - center.x) + r.direction.y * (r.origin.y - center.y) + r.direction.z * (r.origin.z - center.z));
    double c_ = (r.origin.x - center.x) * (r.origin.x - center.x) + (r.origin.y - center.y) * (r.origin.y - center.y) + (r.origin.z - center.z) * (r.origin.z - center.z) - radius * radius;
    double delta = b_ * b_ - 4 * c_;
    if (delta < 0) {
        res.type = NO_HIT;
        return res;
    }
    double t1 = (-b_ + sqrt(delta)) / 2;
    double t2 = (-b_ - sqrt(delta)) / 2;
    double t = 0;
    if (t1 < 0 && t2 < 0) {
        res.type = NO_HIT;
        return res;
    }
    t = (t2 >= 0 ? t2 : t1);
    res.type = HIT;
    res.t = t;
    res.pos = r.getPoint(res.t);
    if (!usingTexture) {
        res.color = c;
    } else {
        double fi = acos((res.pos.z - center.z) / radius);
        double theta = asin((res.pos.y - center.y) / (radius * sin(fi)));
        double u = theta / (M_PI / 2);
        double v = (M_PI / 2 - fi) / (M_PI / 4);
        if (texture.getMapping(u, v)) {
            res.color = c;
        } else {
            res.color = QColor(255, 255, 255);
        }
    }
    res.normal = r.getPoint(res.t).subtract(center).normalize();
    res.n = n;
    res.kd = kd;
    res.ks = ks;
    return res;
}

void Sphere::setAABB() {
    aabb = AABB(center.subtract(Vec3(radius, radius, radius)), center.add(Vec3(radius, radius, radius)));
}
