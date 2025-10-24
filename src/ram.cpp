#include "./libs/ram.h"

Ram::Ram() {}

Ram::Ram(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_capacity = rec.value("RAM Capacity (GB)").toInt();
    m_speed = rec.value("RAM Speed (MHz)").toInt();
    m_ramType = rec.value("RAM Type").toString();
    m_modules = rec.value("RAM Modules").toInt();
}

Ram::Ram(QString name, int price, QString type, QString image, QString category, int capacity, int speed, QString ramType, int modules)
    : Component(name, price, type, image, category), m_capacity(capacity), m_speed(speed), m_ramType(ramType), m_modules(modules) {}
