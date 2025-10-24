#include "./libs/storage.h"

Storage::Storage() {}

Storage::Storage(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_capacity = rec.value("Storage Capacity (GB)").toInt();
    m_storageType = rec.value("Storage Type").toString();
    m_interface = rec.value("Storage Interface").toString();
    m_read_speed = rec.value("Storage Read Speed (MB/s)").toInt();
    m_write_speed = rec.value("Storage Write Speed (MB/s)").toInt();
}

Storage::Storage(QString name, int price, QString type, QString image, QString category, int capacity, QString storageType, QString interface, int read_speed, int write_speed)
    : Component(name, price, type, image, category), m_capacity(capacity), m_storageType(storageType), m_interface(interface), m_read_speed(read_speed), m_write_speed(write_speed) {}
