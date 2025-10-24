#ifndef COOLINGSYSTEM_H
#define COOLINGSYSTEM_H

#include "component.h"

class CoolingSystem : public Component
{
public:
    CoolingSystem();
    CoolingSystem(const QSqlRecord& rec);
    CoolingSystem(QString name, int price, QString type, QString image, QString category, QString coolingType, int noise_level, int radiator_size, int fans);
    //ComponentType cType() const override {return ComponentType::COOLING;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    QString m_coolingType;
    int m_noise_level;
    int m_radiator_size;
    int m_fans;
};

#endif // COOLINGSYSTEM_H
