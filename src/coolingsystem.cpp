#include "./libs/coolingsystem.h"

CoolingSystem::CoolingSystem() {}

CoolingSystem::CoolingSystem(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_coolingType = rec.value("Cooling Type").toString();
    m_noise_level = rec.value("Cooling Noise Level (dB)").toDouble();
    m_radiator_size = rec.value("Cooling Radiator Size (mm)").toDouble();
    m_fans = rec.value("Cooling Fan Count").toInt();
}

CoolingSystem::CoolingSystem(QString name, int price, QString type, QString image, QString category, QString coolingType, int noise_level, int radiator_size, int fans)
    : Component(name, price, type, image, category), m_coolingType(coolingType), m_noise_level(noise_level), m_radiator_size(radiator_size), m_fans(fans) {}
