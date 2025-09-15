#include "stackedbudgetbar.h"

StackedBudgetBar::StackedBudgetBar(const std::vector<Component> &components, QWidget *parent)
    : QWidget(parent), m_components(components)
{}

void StackedBudgetBar::setSelectedIndex(int index) {
    if (index >= 0 && index < m_components.size()) {
        m_selectedIndex = index;
        update();
    }
}

void StackedBudgetBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    double total = 0;
    for (auto &c : m_components) total += c.price();

    int barHeight = 25;
    int x = 0;
    int y = 0;
    int barMaxWidth = width() - 5;

    for (int i = 0; i < m_components.size(); i++) {
        auto &c = m_components[i];
        double ratio = c.price() / total;
        int sliceWidth = static_cast<int>(ratio * barMaxWidth);

        QRect rect(x, y, sliceWidth, barHeight);

        QColor color;
        if (i == m_selectedIndex) {
            color = QColor(93, 153, 19, 255);
        } else {
            color = QColor(36, 76, 18, 255);
        }

        painter.setBrush(color);
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(rect,9,9);

        x += sliceWidth;
    }
}
