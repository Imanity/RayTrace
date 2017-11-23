#include "objloader.h"
#include <QDebug>
using namespace std;

ObjLoader::ObjLoader() {

}

ObjLoader::ObjLoader(string filename, Vec3 center, double r) {
    ifstream inFile(filename);
    if (!inFile) {
        return;
    }
    string line;
    while (!inFile.eof()) {
        getline(inFile, line);
        line = line.append(" ");
        vector<string> parameters;
        string parameter;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] != ' ') {
                parameter += line[i];
            } else {
                parameters.push_back(parameter);
                parameter = "";
            }
        }

        if (parameters.size() == 4) {
            if (parameters[0] == "v") {
                vSets.push_back(Vec3(atof(parameters[1].c_str()), atof(parameters[2].c_str()), atof(parameters[3].c_str())));
            } else if (parameters[0] == "f") {
                fSets.push_back(Vec3(atoi(parameters[1].c_str()) - 1, atoi(parameters[2].c_str()) - 1, atoi(parameters[3].c_str()) - 1));
            }
        }
    }
    for (int i = 0; i < vSets.size(); ++i) {
        vSets[i] = vSets[i].multiply(r).add(center);
    }
}

IntersectResult ObjLoader::intersect(Ray r) {
    IntersectResult res;
    double minT = -1;
    Vec3 minPos;
    Vec3 minN;
    for (int i = 0; i < fSets.size(); ++i) {
        double a_ = 1, b_, c_, d_;
        double x1 = vSets[(int)fSets[i].x].x - vSets[(int)fSets[i].y].x;
        double x2 = vSets[(int)fSets[i].x].x - vSets[(int)fSets[i].z].x;
        double y1 = vSets[(int)fSets[i].y].y - vSets[(int)fSets[i].x].y;
        double y2 = vSets[(int)fSets[i].z].y - vSets[(int)fSets[i].x].y;
        double z1 = vSets[(int)fSets[i].y].z - vSets[(int)fSets[i].x].z;
        double z2 = vSets[(int)fSets[i].z].z - vSets[(int)fSets[i].x].z;
        if (z1 * y2 == z2 * y1) {
            c_ = 0;
            if (y1 == 0) {
                b_ = x2 / y2;
            } else {
                b_ = x1 / y1;
            }
        } else {
            c_ = (x1 * y2 - x2 * y1) / (z1 * y2 - z2 * y1);
            if (y1 == 0) {
                b_ = (x2 - c_ * z2) / y2;
            } else {
                b_ = (x1 - c_ * z1) / y1;
            }
        }
        d_ = -(a_ * vSets[(int)fSets[i].x].x + b_ * vSets[(int)fSets[i].x].y + c_ * vSets[(int)fSets[i].x].z);
        Vec3 n_ = Vec3(a_, b_, c_);
        if (n_.dot(r.direction) == 0) {
            continue;
        }
        double t = -(n_.dot(r.origin) + d_) / (n_.dot(r.direction));
        Vec3 p = r.origin.add(r.direction.multiply(t));
        if (minT > 0 && t > minT) {
            continue;
        }
        if (!isInPolygon(p, vSets[(int)fSets[i].x], vSets[(int)fSets[i].y], vSets[(int)fSets[i].z], n_)) {
            continue;
        }
        minT = t;
        minPos = p;
        minN = n_.normalize();
        if (r.direction.dot(minN) > 0) {
            minN = minN.negate();
        }
    }
    if (minT <= 0) {
        res.type = NO_HIT;
        return res;
    }
    res.type = HIT;
    res.color = c;
    res.kd = kd;
    res.ks = ks;
    res.n = n;
    res.normal = minN;
    res.pos = minPos;
    res.t = minT;
    return res;
}

bool ObjLoader::isInPolygon(Vec3 p, Vec3 a, Vec3 b, Vec3 c, Vec3 n) {
    Vec3 a_ = a.subtract(p);
    Vec3 b_ = b.subtract(p);
    Vec3 c_ = c.subtract(p);
    if (a_.length() == 0 || b_.length() == 0 || c_.length() == 0) {
        return true;
    }
    double aTheta = (a_.dot(b_)) / (a_.length() * b_.length());
    double bTheta = (b_.dot(c_)) / (b_.length() * c_.length());
    double cTheta = (a_.dot(c_)) / (a_.length() * c_.length());
    double a1 = acos(aTheta);
    double b1 = acos(bTheta);
    double c1 = acos(cTheta);
    if (a_.cross(b_).dot(n) < 0) {
        a1 = -a1;
    }
    if (b_.cross(c_).dot(n) < 0) {
        b1 = -b1;
    }
    if (c_.cross(a_).dot(n) < 0) {
        c1 = -c1;
    }
    if (abs(a1 + b1 + c1) < 1) {
        return false;
    }
    return true;
}

void ObjLoader::setAABB() {
    double xMin = -DBL_MAX, xMax = DBL_MAX, yMin = -DBL_MAX, yMax = DBL_MAX, zMin = -DBL_MAX, zMax = DBL_MAX;
    for (int i = 0; i < vSets.size(); ++i) {
        if (vSets[i].x < xMin) {
            xMin = vSets[i].x;
        }
        if (vSets[i].x > xMax) {
            xMax = vSets[i].x;
        }
        if (vSets[i].y < yMin) {
            yMin = vSets[i].y;
        }
        if (vSets[i].y > yMax) {
            yMax = vSets[i].y;
        }
        if (vSets[i].z < zMin) {
            zMin = vSets[i].z;
        }
        if (vSets[i].z > zMax) {
            zMax = vSets[i].z;
        }
    }
}
