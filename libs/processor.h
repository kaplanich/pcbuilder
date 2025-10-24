#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "component.h"

class Processor : public Component
{
public:
    Processor();
    Processor(const QSqlRecord& rec);
    Processor(QString name, int price, QString type, QString image, QString category, int cores, int threads, double base_clock, double boost_clock, int tdp);
    //ComponentType cType() const override {return ComponentType::CPU;}
    //bool isEmpty() const override { return this->name().isEmpty();}
    int m_cores;
    int m_threads;
    double m_base_clock;
    double m_boost_clock;
    int m_tdp;
};

#endif // PROCESSOR_H
