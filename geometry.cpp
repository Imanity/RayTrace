#include "geometry.h"

Geometry::Geometry() {
    c = QColor(255, 255, 255);
}

void Geometry::setColor(int r, int g, int b) {
    c = QColor(r, g, b);
}

IntersectResult Geometry::intersect(Ray /*r*/) {
    return IntersectResult();
}

void Geometry::setAABB() {
    //
}
