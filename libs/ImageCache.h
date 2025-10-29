#ifndef IMAGECACHE_H
#define IMAGECACHE_H

#include <QPixmap>
#include <QHash>
#include <QString>

class ImageCache {
public:
    static QPixmap get(const QString &path) {
        static QHash<QString, QPixmap> cache;
        if (!cache.contains(path)) {
            cache.insert(path, QPixmap(path));
        }
        return cache[path];
    }
};

#endif // IMAGECACHE_H
