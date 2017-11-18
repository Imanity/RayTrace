#include "vec3.h"

Vec3::Vec3() {
    x = y = z = 0;
}

Vec3::Vec3(double x_, double y_, double z_) {
    x = x_;
    y = y_;
    z = z_;
}

double Vec3::length() {
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() {
    double len = length();
    if (len == 0) {
        return Vec3(x, y, z);
    }
    return Vec3(x / len, y / len, z / len);
}

Vec3 Vec3::negate() {
    return Vec3(-x, -y, -z);
}

Vec3 Vec3::add(Vec3 v) {
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::subtract(Vec3 v) {
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::multiply(double r) {
    return Vec3(x * r, y * r, z * r);
}

Vec3 Vec3::divide(double r) {
    return Vec3(x / r, y / r, z / r);
}

double Vec3::dot(Vec3 v) {
    return (x * v.x + y * v.y + z * v.z);
}

Vec3 Vec3::cross(Vec3 v) {
    return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
