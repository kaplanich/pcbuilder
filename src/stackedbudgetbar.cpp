#include "./libs/stackedbudgetbar.h"


StackedBudgetBar::StackedBudgetBar(QWidget *parent)
    : QWidget(parent)
{

}

void StackedBudgetBar::setSelectedIndex(int index) {
    if (index >= 0 && index < static_cast<int>(m_components.size())) {
        m_selectedIndex = index;
        update();
    }
}

void StackedBudgetBar::setComponents(const std::unordered_map<QString, Component> components) {
    m_selectedIndex = -1;
    m_components.clear();
    for (const auto& c : components)
        if(!c.second.name().isEmpty())
            m_components.push_back(c.second);
    update();
}


void StackedBudgetBar::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    if (m_components.empty()) return;

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
