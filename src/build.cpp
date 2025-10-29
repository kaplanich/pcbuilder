#include "libs/build.h"

Build::Build() {
    m_components.insert({"cpu", Component()});
    m_components.insert({"gpu", Component()});
    m_components.insert({"psu", Component()});
    m_components.insert({"ram", Component()});
    m_components.insert({"motherboard", Component()});
    m_components.insert({"case", Component()});
    m_components.insert({"storage", Component()});
    m_components.insert({"cooling", Component()});
}

void Build::addComponent(Component* c) {
    QString type = c->type();

    m_components[type] = *c;
    calculateTotalCost();
}

void Build::calculateTotalCost() {
    int total = 0;

    for (auto& c : m_components) {
        if(!c.second.name().isEmpty())
            total += c.second.price();
    }

    m_totalcost = total;
}

void Build::deleteComponent(QString type) {
    for (auto& c : m_components) {
        if(c.second.type() == type) m_components[type] = Component();
    }
    calculateTotalCost();
}

