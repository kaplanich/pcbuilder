#include "libs/component.h"

Component::Component()
{}


Component::Component(QString name, int price, QString type, QString image, QString category) {
    m_name = name;
    m_price = price;
    m_type = type;
    m_image = image;
    m_category = category;
}
