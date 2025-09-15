#pragma once
#include <QString>

class Component {
public:
    Component(const QString &name, double price, QString type)
        : m_name(name), m_price(price), m_type(type) {}

    const QString& name() const { return m_name; }
    const QString& type() const { return m_type; }
    double price() const { return m_price; }

private:
    QString m_name;
    QString m_type;
    double m_price;
};
