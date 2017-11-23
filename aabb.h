#ifndef AABB_H
#define AABB_H

#include "vec3.h"

class AABB {
public:
    Vec3 minCorner, maxCorner;

public:
    AABB();
    AABB(Vec3 min, Vec3 max);

    bool isCollided(Vec3 p);
};

#endif // AABB_H
