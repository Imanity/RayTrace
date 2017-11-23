#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QColor>

#include "utility.h"
#include "ray.h"
#include "aabb.h"

class Geometry {
public:
    // For Phong Model
    QColor c;
    int n;
    double kd, ks;
    AABB aabb;

public:
    Geometry();

    void setColor(int r, int g, int b);
    virtual void setAABB();
    virtual IntersectResult intersect(Ray /*r*/);
};

#endif // GEOMETRY_H
