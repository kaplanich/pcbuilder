#include "libs/build.h"

Build::Build() {
    m_components.insert({"cpu", Processor()});
    m_components.insert({"gpu", GraphicCard()});
    m_components.insert({"psu", Psu()});
    m_components.insert({"ram", Ram()});
    m_components.insert({"motherboard", Motherboard()});
    m_components.insert({"case", Case()});
    m_components.insert({"storage", Storage()});
    m_components.insert({"cooling", CoolingSystem()});
}

void Build::addComponent(Component& c) {
    QString type = c.type();

    m_components[type] = c;
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

