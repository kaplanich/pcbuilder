#ifndef CASE_H
#define CASE_H

#include "component.h"

class Case : public Component
{
public:
    Case();
    Case(const QSqlRecord& rec);
    Case(QString name, int price, QString type, QString image, QString category, QString form_factor, QString color, QString material, int fans, int max_gpu_length);
    //ComponentType cType() const override {return ComponentType::CASE;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    QString m_form_factor;
    QString m_color;
    QString m_material;
    int m_fans;
    int m_max_gpu_length;
};

#endif // CASE_H
