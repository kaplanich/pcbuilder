#ifndef COMPONENTTILE_H
#define COMPONENTTILE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include "./libs/component.h"

class ComponentTile : public QFrame
{
    Q_OBJECT

public:
    explicit ComponentTile(Component &c, int index, QWidget *parent = nullptr);
    void setSelected(bool selected);
    QWidget* categoryAndCost;
    QVBoxLayout* mainLayout;
    QHBoxLayout* categoryAndCostLayout;
    QLabel* compName;
    QLabel* compCost;
    QLabel* compType;


signals:
    void clicked(int index);
    void tileSelected(ComponentTile* tile);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

private:
    int m_index = 0;
    bool m_selected = true;
};

#endif // COMPONENTTILE_H
