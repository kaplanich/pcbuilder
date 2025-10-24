#ifndef MOTHERBOARD_H
#define MOTHERBOARD_H

#include "component.h"

class Motherboard : public Component
{
public:
    Motherboard();
    Motherboard(const QSqlRecord& rec);
    Motherboard(QString name, int price, QString type, QString image, QString category, QString socket, QString chipset, QString form_factor, int ram_slots, int max_ram);
    //ComponentType cType() const override {return ComponentType::MOTHERBOARD;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    QString m_socket;
    QString m_chipset;
    QString m_form_factor;
    int m_ram_slots;
    int m_max_ram;
};

#endif // MOTHERBOARD_H
