#ifndef UTILITY_H
#define UTILITY_H

#include <QColor>

#include "vec3.h"

#define NO_HIT 0
#define HIT 1

struct IntersectResult {
    int type;
    double t;
    Vec3 pos;
    Vec3 normal;

    // For Phong Model
    QColor color;
    int n;
    double kd, ks;

    IntersectResult() { type = NO_HIT; }
};

// I = Ip * Kd * (L dot N) + Ip * Ks * (H dot N) ^ n
QColor phong(double kd, double ks, Vec3 l, Vec3 n, Vec3 v, QColor c, int shininess);

QColor modulate(QColor &c1, QColor &c2, double ks);

#endif // UTILITY_H
