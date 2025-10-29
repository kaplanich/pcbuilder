#include "libs/componentlistwidget.h"

ComponentListWidget::ComponentListWidget(Component& cmp, QWidget *parent)
    : component(cmp), QWidget{parent}
{
    layout = new QHBoxLayout(this);
    setFixedHeight(80);
    QLabel* img = new QLabel(this);
    QLabel* name = new QLabel(cmp.name(), this);
    QLabel* category = new QLabel(cmp.category(), this);
    QLabel* price = new QLabel("$" + QString::number(cmp.price()), this);
    QPushButton* features = new QPushButton("See features list", this);
    QPushButton* deleteComponent = new QPushButton("—",this);
    QFont font("Segoe UI",10,500);

    img->setPixmap(cmp.image());
    img->setFixedSize(60,60);
    img->setScaledContents(true);
    features->setStyleSheet("QPushButton::hover {color: rgb(82, 82, 82);}");
    deleteComponent->setStyleSheet("QPushButton {\n	background-color: rgb(42, 42, 42);\n	border-radius: 9px;\n}\n\nQPushButton:hover {\n	background-color: rgb(64, 64, 64);\n}");
    deleteComponent->setFixedSize(30,30);

    layout->addWidget(img);
    layout->addWidget(name);
    layout->addWidget(category);
    layout->addWidget(price);
    layout->addWidget(features);
    layout->addWidget(deleteComponent);

    setFont(font);


    connect(deleteComponent, &QPushButton::clicked, this, &ComponentListWidget::deleteTheComponent);
}


void ComponentListWidget::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QColor::fromRgb(153, 153, 153, 50));
    painter.drawRect(0,79,width()-10, 1);

    QWidget::paintEvent(e);
}

void ComponentListWidget::deleteTheComponent() {
    emit componentDeleted(component.type());
}
