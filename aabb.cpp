#include "aabb.h"

AABB::AABB() {
    minCorner = Vec3(0, 0, 0);
    maxCorner = Vec3(1, 1, 1);
}

AABB::AABB(Vec3 min, Vec3 max) {
    minCorner = min;
    maxCorner = max;
}

bool AABB::isCollided(Vec3 p) {
    if (p.x < minCorner.x || p.x > maxCorner.x) {
        return false;
    }
    if (p.y < minCorner.y || p.y > maxCorner.y) {
        return false;
    }
    if (p.z < minCorner.z || p.z > maxCorner.z) {
        return false;
    }
    return true;
}
