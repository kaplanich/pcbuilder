#ifndef PSU_H
#define PSU_H

#include "component.h"

class Psu : public Component
{
public:
    Psu();
    Psu(const QSqlRecord& rec);
    Psu(QString name, int price, QString type, QString image, QString category, int wattage, QString efficiency, QString modular);
    //ComponentType cType() const override {return ComponentType::PSU;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    int m_wattage;
    QString m_efficiency;
    QString m_modular;
};

#endif // PSU_H
