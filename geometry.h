#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QColor>

#include "utility.h"
#include "ray.h"

class Geometry {
public:
    QColor c;

public:
    Geometry();

    void setColor(int r, int g, int b);
    virtual IntersectResult intersect(Ray /*r*/);
};

#endif // GEOMETRY_H
