

#include "rectangle.h"

namespace Shapes {
    Shapes::Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) {
        xF = xFrom;
        yF = yFrom;
        xT = xTo;
        yT = yTo;
    }

    bool Shapes::Rectangle::isIn(int x, int y) const {
        return ((x >= xF && x <= xT && y <= yT && y >= yF));
    }
}