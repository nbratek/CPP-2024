
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes {
    class Rectangle : public Shapes::Shape {
    private:
        int xF;
        int yF;
        int xT;
        int yT;

    public:
        Rectangle(int xFrom, int yFrom, int xTo, int yTo);

        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const { return xF; }
        [[nodiscard]] int y() const { return yF; }
        [[nodiscard]] int xTo() const { return xT; }
        [[nodiscard]] int yTo() const { return yT; }
    };
}

#endif //RECTANGLE_H
