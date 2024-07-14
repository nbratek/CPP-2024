
#include "shapecomposite.h"

#include <utility>

Shapes::ShapeComposite::ShapeComposite(std::shared_ptr <Shape> shape1, std::shared_ptr <Shape> shape2, ShapeOperation shapeOperation) {
    sh1 = std::move(shape1);
    sh2 = std::move(shape2);
    op = shapeOperation;
}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    if (op == ShapeOperation::SUM){
        bool result1 = sh1->isIn(x, y);
        bool result2 = sh2->isIn(x, y);
        if (result1 || result2){
            return true;
        }
    }
    else if (op == ShapeOperation::INTERSECTION){
        bool result1 = sh1->isIn(x, y);
        bool result2 = sh2->isIn(x, y);
        if (result1 && result2){
            return true;
        }
    }
    else if (op == ShapeOperation::DIFFERENCE){
        bool result1 = sh1->isIn(x, y);
        bool result2 = sh2->isIn(x, y);
        if (result1 && !result2){
            return true;
        }
    }
    return false;
}
