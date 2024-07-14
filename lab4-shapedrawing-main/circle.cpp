
#include "circle.h"

Shapes::Circle::Circle(int xCenter, int yCenter, int radius) {
    xc = xCenter;
    yc = yCenter;
    rc = radius;
}

bool Shapes::Circle::isIn(int x, int y) const {
    return (((xc - x) * (xc - x) + (yc - y) * (yc - y)) <= rc * rc);
}
