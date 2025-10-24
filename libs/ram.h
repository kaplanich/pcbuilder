#ifndef RAM_H
#define RAM_H

#include "component.h"

class Ram : public Component
{
public:
    Ram();
    Ram(const QSqlRecord& rec);
    Ram(QString name, int price, QString type, QString image, QString category, int capacity, int speed, QString ramType, int modules);
    //ComponentType cType() const override {return ComponentType::RAM;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    int m_capacity;
    int m_speed;
    QString m_ramType;
    int m_modules;
};

#endif // RAM_H
