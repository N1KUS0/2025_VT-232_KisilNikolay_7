#ifndef ROOM_H
#define ROOM_H

#include "Furniture.h"
#include "SmartPtr.h"
#include <QList>
#include <QString>
#include <QRect>
#include <QColor>
#include <QPainter>

class Room {
    QString name;
    QRect geometry;
    QColor wallColor;
    QList<SmartPtr<Furniture>> furniture;
public:
    Room(QString name, const QRect& geom, const QColor& wallColor);

    void draw(QPainter& painter) const;
    void addFurniture(SmartPtr<Furniture> item);

    bool saveToFile(const QString& filename) const;
    static SmartPtr<Room> loadFromFile(const QString& filename);

    // Другие методы
    QString getName() const { return name; }
    QRect getGeometry() const { return geometry; }
};

#endif // ROOM_H
