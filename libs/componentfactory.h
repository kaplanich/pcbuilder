#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <QSqlRecord>
#include <QVariant>
#include <QString>
#include <unordered_map>
#include <memory>
#include <QDebug>
#include "component.h"

class ComponentFactory {
public:
    static ComponentFactory& instance();

    Component* create(const QSqlRecord& rec) const;

    template <typename T>
    void registerType(const QString& type) {
        creators[type.toLower()] = &ComponentFactory::createInstance<T>;
    }

private:
    ComponentFactory() = default;

    template <typename T>
    static Component* createInstance(const QSqlRecord& rec) {
        return new T(rec);
    }

    std::unordered_map<QString, Component*(*)(const QSqlRecord&)> creators;
};


#endif // COMPONENTFACTORY_H
