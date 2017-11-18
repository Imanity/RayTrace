#include "raytracer.h"

RayTracer::RayTracer() {

}

QColor RayTracer::rayTrace(Scene &s, Ray &r) {
    QColor c = QColor(0, 0, 0);
    IntersectResult res = s.intersect(r);
    if (res.type == HIT) {
        c = res.color;
    }
    return c;
}
