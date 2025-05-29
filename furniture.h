#ifndef FURNITURE_H
#define FURNITURE_H

#include <QString>
#include <QRect>
#include <QColor>
#include <QPainter>

class Furniture {
    QString name;
    QRect geometry;
    QColor color;
public:
    Furniture(QString name, const QRect& geom, const QColor& color);

    void draw(QPainter& painter) const;

    QString getName() const;
    QRect getGeometry() const;
    QColor getColor() const;

    void setGeometry(const QRect& geom);
    void setColor(const QColor& col);
};

#endif // FURNITURE_H
