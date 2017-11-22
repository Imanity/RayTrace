#include "chesstexture.h"

ChessTexture::ChessTexture() {

}

ChessTexture::ChessTexture(int d) {
    this->d = d;
}

bool ChessTexture::getMapping(double u, double v) {
    return int(floor(u * d) + floor(v * d)) % 2;
}
