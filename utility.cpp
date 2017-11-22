#include "utility.h"

// I = Ip * Kd * (L dot N) + Ip * Ks * (H dot N) ^ n
QColor phong(double kd, double ks, Vec3 l, Vec3 n, Vec3 v, QColor c, int shininess) {
    Vec3 Ip = Vec3((double)c.red() / 255.0, (double)c.green() / 255, (double)c.blue() / 255);
    double ldotn = 0, hdotn = 0;
    ldotn = l.dot(n);
    hdotn = l.add(v).normalize().dot(n);
    Vec3 diffuseTerm = Ip.multiply(kd * ldotn);
    Vec3 specularTerm = Ip.multiply(ks * pow(hdotn, shininess));
    Vec3 I = diffuseTerm.add(specularTerm);
    I.x = I.x < 0 ? 0 : I.x;
    I.x = I.x > 1 ? 1 : I.x;
    I.y = I.y < 0 ? 0 : I.y;
    I.y = I.y > 1 ? 1 : I.y;
    I.z = I.z < 0 ? 0 : I.z;
    I.z = I.z > 1 ? 1 : I.z;
    return QColor(I.x * 255, I.y * 255, I.z * 255);
}

QColor modulate(QColor &c1, QColor &c2, double ks) {
    int r = c1.red() + c2.red() * ks;
    int g = c1.green() + c2.green() * ks;
    int b = c1.blue() + c2.blue() * ks;
    r = r < 0 ? 0 : r;
    r = r > 255 ? 255 : r;
    g = g < 0 ? 0 : g;
    g = g > 255 ? 255 : g;
    b = b < 0 ? 0 : b;
    b = b > 255 ? 255 : b;
    return QColor(r, g, b);
}
