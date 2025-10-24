#pragma once
#include <QWidget>
#include <vector>
#include <QPainter>
#include <QSqlRecord>
#include "component.h"

class StackedBudgetBar : public QWidget {
    Q_OBJECT
public:
    explicit StackedBudgetBar(QWidget *parent = nullptr);

    void setSelectedIndex(int index);
    void setComponents(const std::unordered_map<QString, Component> components);

private:
    std::vector<Component> m_components;
    int m_selectedIndex = -1;

protected:
    void paintEvent(QPaintEvent *event) override;
};
