#include "raytracer.h"

RayTracer::RayTracer() {

}

QColor RayTracer::rayTrace(Scene &s, Ray r, int depth) {
    QColor c = QColor(0, 0, 0);
    if (depth > 3) {
        return c;
    }
    IntersectResult res = s.intersect(r);
    if (res.type == HIT) {
        QColor cl = phong(res.kd, res.ks, s.light.getL(res.pos), res.normal, r.origin.subtract(res.pos).normalize(), res.color, res.n);
        Ray shadowTestRay = Ray(s.light.pos, s.light.getL(res.pos).negate());
        double shadowRate = 0.5;
        if (!shadowTest(s, shadowTestRay, res.pos)) {
            cl = QColor(cl.red() * shadowRate, cl.green() * shadowRate, cl.red() * shadowRate);
        }

        Vec3 n = res.normal;
        Vec3 in = r.direction;
        Vec3 inV = n.multiply(in.dot(n));
        Vec3 inH = in.subtract(inV);
        Vec3 out = inH.subtract(inV);
        QColor cs = rayTrace(s, Ray(res.pos.add(n.multiply(eps)), out), depth + 1);
        c = modulate(cl, cs, res.ks);
    }
    return c;
}

bool RayTracer::shadowTest(Scene &s, Ray r, Vec3 pos) {
    Vec3 p = s.intersect(r).pos;
    double dis = sqrt((p.x - pos.x) * (p.x - pos.x) + (p.y - pos.y) * (p.y - pos.y) + (p.z - pos.z) * (p.z - pos.z));
    return dis < eps;
}
