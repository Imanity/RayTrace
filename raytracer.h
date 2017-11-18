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
    QColor rayTrace(Scene &s, Ray &r);
};

#endif // RAYTRACER_H
