#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "ray.h"
#include "plane.h"
#include "utility.h"

class Scene {
private:
    std::vector<Plane> planes;

public:
    Scene();

    void addPlane(Plane p);
    IntersectResult intersect(Ray r);
};

#endif // SCENE_H
