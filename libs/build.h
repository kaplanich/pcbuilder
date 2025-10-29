#ifndef BUILD_H
#define BUILD_H

#include "ComponentsLib.h"

class Build
{
public:
    Build();
    void addComponent(Component* c);
    void calculateTotalCost();
    std::unordered_map<QString, Component> getAllComponents() const {return m_components;}
    int getTotalCost() const {return m_totalcost;}
    void deleteComponent(QString type);


private:
    int m_totalcost = 0;
    std::unordered_map<QString, Component> m_components;
};


#endif // BUILD_H
