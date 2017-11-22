#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QColor>
#include <QDebug>

#include "scene.h"
#include "plane.h"
#include "ray.h"

class RayTracer {
public:
    RayTracer();

public:
    double eps = 0.01;
    QColor rayTrace(Scene &s, Ray r, int depth);

private:
    bool shadowTest(Scene &s, Ray r, Vec3 pos);
};

#endif // RAYTRACER_H
