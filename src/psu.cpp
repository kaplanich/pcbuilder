#include "./libs/psu.h"

Psu::Psu() {}

Psu::Psu(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_wattage = rec.value("PSU Wattage (W)").toInt();
    m_efficiency = rec.value("PSU Efficiency").toString();
    m_modular = rec.value("PSU Modular").toString();
}

Psu::Psu(QString name, int price, QString type, QString image, QString category, int wattage, QString efficiency, QString modular)
    : Component(name, price, type, image, category), m_wattage(wattage), m_efficiency(efficiency), m_modular(modular) {}
