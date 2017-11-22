#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "ray.h"
#include "plane.h"
#include "sphere.h"
#include "utility.h"
#include "pointlight.h"

class Scene {
public:
    std::vector<Plane> planes;
    std::vector<Sphere> spheres;

    PointLight light;

public:
    Scene();

    void addPlane(Plane p);
    void addSphere(Sphere s);
    IntersectResult intersect(Ray r);
};

#endif // SCENE_H
