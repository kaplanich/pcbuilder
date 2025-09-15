#pragma once
#include <QWidget>
#include <vector>
#include <QPainter>
#include "computerpart.h"

class StackedBudgetBar : public QWidget {
    Q_OBJECT
public:
    explicit StackedBudgetBar(const std::vector<Component> &components, QWidget *parent = nullptr);

    void setSelectedIndex(int index);

private:
    std::vector<Component> m_components;
    int m_selectedIndex = -1;

protected:
    void paintEvent(QPaintEvent *event) override;
};
