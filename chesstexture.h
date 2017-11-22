#ifndef CHESSTEXTURE_H
#define CHESSTEXTURE_H

#include <cmath>

class ChessTexture {
public:
    int d = 8;
public:
    ChessTexture();
    ChessTexture(int d);

    bool getMapping(double u, double v);
};

#endif // CHESSTEXTURE_H
