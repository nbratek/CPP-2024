

#ifndef SHAPECOMPOSITE_H
#define SHAPECOMPOSITE_H

#include "shape.h"
#include <memory>

namespace Shapes {
    enum class ShapeOperation {
        INTERSECTION,
        SUM,
        DIFFERENCE
    };
    class ShapeComposite : public Shapes::Shape {
    private:
        std::shared_ptr<Shape> sh1;
        std::shared_ptr<Shape> sh2;
        enum ShapeOperation op;

    public:
        ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, ShapeOperation shapeOperation);

        [[nodiscard]] bool isIn(int x, int y) const override;


    };
}




#endif //SHAPECOMPOSITE_H
