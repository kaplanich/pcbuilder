#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QString>
#include <QSqlRecord>
#include <QVariant>

// enum ComponentType {
//     CPU,
//     GPU,
//     RAM,
//     STORAGE,
//     MOTHERBOARD,
//     COOLING,
//     PSU,
//     CASE
// };

class Component
{
public:
    explicit Component();
    Component(QString name, int price, QString type, QString image, QString category);
    QString type() const {return m_type;}
    QString name() const {return m_name;}
    int price() const {return m_price;}
    QString image() const {return m_image;}
    QString category() const {return m_category;}
    // virtual ComponentType cType() const = 0;
    // virtual bool isEmpty() const { return false; }

private:
    QString m_type;
    QString m_name;
    int m_price;
    QString m_image;
    QString m_category;

signals:
};

#endif // COMPONENT_H
