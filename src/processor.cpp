#include "./libs/processor.h"

Processor::Processor() {}

Processor::Processor(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_cores = rec.value("CPU Cores").toInt();
    m_threads = rec.value("CPU Threads").toInt();
    m_base_clock = rec.value("CPU Base Clock (GHz)").toDouble();
    m_boost_clock = rec.value("CPU Boost Clock (GHz)").toDouble();
    m_tdp = rec.value("CPU TDP (W)").toDouble();
}

Processor::Processor(QString name, int price, QString type, QString image, QString category, int cores, int threads, double base_clock, double boost_clock, int tdp)
    : Component(name, price, type, image, category), m_cores(cores), m_threads(threads), m_base_clock(base_clock), m_boost_clock(boost_clock), m_tdp(tdp) {}
