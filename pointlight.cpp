#include "pointlight.h"

PointLight::PointLight() {
    color = QColor(255, 255, 255);
    pos = Vec3(0, 0, 15);
}

PointLight::PointLight(QColor c, Vec3 p) {
    color = c;
    pos = p;
}

Vec3 PointLight::getL(Vec3 p) {
    return pos.subtract(p).normalize();
}
