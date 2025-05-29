#ifndef TABLE_H
#define TABLE_H

#include "furniture.h"
#include <QPainter>

class Table : public Furniture {
public:
    Table(QPoint pos, QSize size) : Furniture("Table", pos, size) {}

    void draw(QPainter& painter) override {
        painter.drawRect(QRect(position, size));
        painter.drawText(position + QPoint(5,15), "Table");
    }
};

#endif // TABLE_H
