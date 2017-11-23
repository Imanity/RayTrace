#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "ray.h"
#include "plane.h"
#include "sphere.h"
#include "objloader.h"
#include "utility.h"
#include "pointlight.h"

class Scene {
public:
    std::vector<Plane> planes;
    std::vector<Sphere> spheres;
    std::vector<ObjLoader> objs;

    PointLight light;

public:
    Scene();

    void addPlane(Plane p);
    void addSphere(Sphere s);
    void addObj(ObjLoader o);
    IntersectResult intersect(Ray r);
    bool isCollided(Vec3 p);
};

#endif // SCENE_H
