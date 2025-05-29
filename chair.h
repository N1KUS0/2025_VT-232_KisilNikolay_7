#ifndef CHAIR_H
#define CHAIR_H

#include "furniture.h"
#include <QPainter>

class Chair : public Furniture {
public:
    Chair(QPoint pos, QSize size) : Furniture("Chair", pos, size) {}

    void draw(QPainter& painter) override {
        painter.drawRect(QRect(position, size));
        painter.drawText(position + QPoint(5,15), "Chair");
    }
};

#endif // CHAIR_H
