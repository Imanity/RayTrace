#ifndef UTILITY_H
#define UTILITY_H

#include <QColor>

#include "vec3.h"
#include "geometry.h"

#define NO_HIT 0
#define HIT 1

struct IntersectResult {
    int type;
    QColor color;
    double t;
    Vec3 pos;
    IntersectResult() { type = NO_HIT; }
};

#endif // UTILITY_H
