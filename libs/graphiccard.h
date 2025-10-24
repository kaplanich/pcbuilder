#ifndef GRAPHICCARD_H
#define GRAPHICCARD_H

#include "component.h"

class GraphicCard : public Component
{
public:
    GraphicCard();
    GraphicCard(const QSqlRecord& rec);
    GraphicCard(QString name, int price, QString type, QString image, QString category, int memory, int freq, int tdp, QString interface);
    //ComponentType cType() const override {return ComponentType::GPU;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    int m_memory;
    int m_freq;
    int m_tdp;
    QString m_interface;
};

#endif // GRAPHICCARD_H
