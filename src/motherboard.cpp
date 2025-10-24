#include "./libs/motherboard.h"

Motherboard::Motherboard() {}

Motherboard::Motherboard(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_socket = rec.value("Motherboard Socket").toString();
    m_chipset = rec.value("Motherboard Chipset").toString();
    m_form_factor = rec.value("Motherboard Form Factor").toString();
    m_ram_slots = rec.value("Motherboard RAM Slots").toInt();
    m_max_ram = rec.value("Motherboard Max RAM (GB)").toInt();
}

Motherboard::Motherboard(QString name, int price, QString type, QString image, QString category, QString socket, QString chipset, QString form_factor, int ram_slots, int max_ram)
    : Component(name, price, type, image, category), m_socket(socket), m_chipset(chipset), m_form_factor(form_factor), m_ram_slots(ram_slots), m_max_ram(max_ram) {}
