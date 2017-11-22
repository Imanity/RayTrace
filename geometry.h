#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QColor>

#include "utility.h"
#include "ray.h"

class Geometry {
public:
    // For Phong Model
    QColor c;
    int n;
    double kd, ks;

public:
    Geometry();

    void setColor(int r, int g, int b);
    virtual IntersectResult intersect(Ray /*r*/);
};

#endif // GEOMETRY_H
