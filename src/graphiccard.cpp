#include "./libs/graphiccard.h"

GraphicCard::GraphicCard(){}
GraphicCard::GraphicCard(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString()) {
    m_memory = rec.value("GPU Memory (GB)").toInt();
    m_freq = rec.value("GPU Core Frequency (MHz)").toDouble();
    m_tdp = rec.value("GPU TDP (W)").toInt();
    m_interface = rec.value("GPU Interface").toString();
}

GraphicCard::GraphicCard(QString name, int price, QString type, QString image, QString category, int memory, int freq, int tdp, QString interface)
    : Component(name, price, type, image, category), m_memory(memory), m_freq(freq), m_tdp(tdp), m_interface(interface) {}
