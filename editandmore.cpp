#include "editandmore.h"


EditAndMore::EditAndMore(QWidget *parent)
    : QWidget{parent}
{

    QGridLayout* mainLayout = new QGridLayout(this);
    editBtn = new QPushButton("Edit");
    moreBtn = new QPushButton("···");
    editBtn->setMinimumHeight(32);
    moreBtn->setMinimumHeight(32);
    mainLayout->addWidget(editBtn, 0, 0);
    mainLayout->addWidget(moreBtn, 0, 1);
}
