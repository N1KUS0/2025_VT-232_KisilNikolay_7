#ifndef FURNITURE_H
#define FURNITURE_H

#include <QString>
#include <QPoint>

class Furniture {
protected:
    QString name;
    QPoint position;
    QSize size;

public:
    Furniture(const QString& n, QPoint p, QSize s)
        : name(n), position(p), size(s) {}

    virtual ~Furniture() = default;

    virtual void draw(QPainter& painter) = 0;

    QPoint getPosition() const { return position; }
    QSize getSize() const { return size; }
    QString getName() const { return name; }
};

#endif
