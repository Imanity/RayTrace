#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <QColor>

#include <vec3.h>

class PointLight {
public:
    QColor color;
    Vec3 pos;

public:
    PointLight();
    PointLight(QColor c, Vec3 p);

    Vec3 getL(Vec3 p);
};

#endif // POINTLIGHT_H
