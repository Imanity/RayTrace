#include "scene.h"

Scene::Scene() {

}

void Scene::addPlane(Plane p) {
    planes.push_back(p);
}

IntersectResult Scene::intersect(Ray r) {
    double minT = -1;
    IntersectResult minRes = IntersectResult();
    for (int i = 0; i < planes.size(); ++i) {
        IntersectResult tmpRes = planes[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    return minRes;
}
