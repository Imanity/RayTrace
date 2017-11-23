#include "scene.h"

Scene::Scene() {

}

void Scene::addPlane(Plane p) {
    planes.push_back(p);
}

void Scene::addSphere(Sphere s) {
    spheres.push_back(s);
}

void Scene::addObj(ObjLoader o) {
    objs.push_back(o);
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
    for (int i = 0; i < spheres.size(); ++i) {
        IntersectResult tmpRes = spheres[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    for (int i = 0; i < objs.size(); ++i) {
        IntersectResult tmpRes = objs[i].intersect(r);
        if (tmpRes.type == HIT && (minT < 0 || tmpRes.t < minT)) {
            minT = tmpRes.t;
            minRes = tmpRes;
        }
    }
    return minRes;
}

bool Scene::isCollided(Vec3 p) {
    for (int i = 0; i < spheres.size(); ++i) {
        if (spheres[i].aabb.isCollided(p)) {
            return true;
        }
    }
    for (int i = 0; i < objs.size(); ++i) {
        if (objs[i].aabb.isCollided(p)) {
            return true;
        }
    }
    return false;
}
