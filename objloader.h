#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <fstream>
#include <vector>

#include "geometry.h"

#define M_PI 3.1416

class ObjLoader : public Geometry {
public:
    std::vector<Vec3> vSets;
    std::vector<Vec3> fSets;

public:
    ObjLoader();
    ObjLoader(std::string filename, Vec3 center, double r);

    IntersectResult intersect(Ray r);
    void setAABB();

private:
    bool isInPolygon(Vec3 p, Vec3 a, Vec3 b, Vec3 c, Vec3 n);
};

#endif // OBJLOADER_H
