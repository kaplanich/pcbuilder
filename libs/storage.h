#ifndef STORAGE_H
#define STORAGE_H

#include "component.h"

class Storage : public Component
{
public:
    Storage();
    Storage(const QSqlRecord& rec);
    Storage(QString name, int price, QString type, QString image, QString category, int capacity, QString storageType, QString interface, int read_speed, int write_speed);
    //ComponentType cType() const override {return ComponentType::STORAGE;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    int m_capacity;
    QString m_storageType;
    QString m_interface;
    int m_read_speed;
    int m_write_speed;
};

#endif // STORAGE_H
