#include "./libs/case.h"

Case::Case() {}

Case::Case(const QSqlRecord& rec) : Component(rec.value("Name").toString(), rec.value("Price").toInt(), rec.value("Type").toString(), rec.value("Image").toString(), rec.value("Category").toString())
{
    m_form_factor = rec.value("Case Form Factor").toString();
    m_color = rec.value("Case Color").toString();
    m_material = rec.value("Case Material").toString();
    m_fans = rec.value("Case Fans Included").toInt();
    m_max_gpu_length = rec.value("Case Max GPU Length (mm)").toInt();
}

Case::Case(QString name, int price, QString type, QString image, QString category, QString form_factor, QString color, QString material, int fans, int max_gpu_length)
    : Component(name, price, type, image, category), m_form_factor(form_factor), m_color(color), m_material(material), m_fans(fans), m_max_gpu_length(max_gpu_length) {}
