#include "libs/componentfactory.h"

ComponentFactory& ComponentFactory::instance() {
    static ComponentFactory factory;
    return factory;
}

Component* ComponentFactory::create(const QSqlRecord& rec) const {
    QString type = rec.value("Type").toString().toLower();

    auto it = creators.find(type);
    if (it != creators.end()) {
        return it->second(rec);
    }

    qWarning() << "Unknown component type:" << type;
    return nullptr;
}
