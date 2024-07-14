
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"


namespace Shapes {
    class Circle : public Shapes::Shape {
    private:
        int xc;
        int yc;
        int rc;

    public:
        Circle(int xCenter, int yCenter, int radius);

        [[nodiscard]] bool isIn(int x, int y) const override;

        [[nodiscard]] int x() const { return xc; }

        [[nodiscard]] int y() const { return yc; }

        [[nodiscard]] int radius() const { return rc; }

    };
}




#endif //CIRCLE_H
