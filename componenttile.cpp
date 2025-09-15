#include "componenttile.h"

ComponentTile::ComponentTile(Component& c, int index, QWidget *parent)
    : QFrame{parent}, m_index(index)
{
    this->setFixedSize(300,130);
    this->setStyleSheet("background-color: rgba(35, 35, 35, 1);\n border-radius:12px");

    mainLayout = new QVBoxLayout(this);
    typeAndCost = new QWidget(this);
    typeAndCostLayout = new QHBoxLayout(typeAndCost);
    compType = new QLabel(c.type(), this);
    compCost = new QLabel("$" + QString::number(c.price()), this);
    compName = new QLabel(c.name(), this);

    typeAndCost->setStyleSheet("color: rgba(240, 240, 240, 0.7);");
    compName->setStyleSheet("font-size:18px");

    this->setLayout(mainLayout);

    compType->setMinimumWidth(250);
    compCost->setMinimumWidth(50);
    typeAndCostLayout->setContentsMargins(0,0,0,0);
    typeAndCostLayout->addWidget(compType);
    typeAndCostLayout->addWidget(compCost);
    mainLayout->setContentsMargins(15,0,0,11);
    mainLayout->addWidget(typeAndCost);
    mainLayout->addWidget(compName);
}

void ComponentTile::mousePressEvent(QMouseEvent *event) {
    emit clicked(m_index);
    emit tileSelected(this);
    QWidget::mousePressEvent(event);
}

void ComponentTile::setSelected(bool selected) {
    m_selected = selected;
    if (m_selected) {
        this->setStyleSheet("ComponentTile {border: 1px solid rgba(153, 153, 153, 0.6); border-radius:12px; background-color: rgba(35, 35, 35, 1);} QLabel {background-color: rgba(35, 35, 35, 1); border-radius:12px} ");
    } else {
        this->setStyleSheet("background-color: rgba(35, 35, 35, 1); border-radius:12px;");
    }
}

void ComponentTile::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QRect r = rect().adjusted(2, 2, -2, -2);
    QPainterPath path;
    path.addRoundedRect(r, 12, 12);
    p.fillPath(path, QColor(35, 35, 35));
}
