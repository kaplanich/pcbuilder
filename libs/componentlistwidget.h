#ifndef COMPONENTLISTWIDGET_H
#define COMPONENTLISTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPushButton>
#include "build.h"
#include "libs/component.h"

class ComponentListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ComponentListWidget(Component& cmp, QWidget *parent = nullptr);
    QHBoxLayout* layout;
    Component component;
private:
    void paintEvent(QPaintEvent* e);
    void deleteTheComponent();
signals:
    void componentDeleted(QString type);
};

#endif // COMPONENTLISTWIDGET_H
