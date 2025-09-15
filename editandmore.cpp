#include "editandmore.h"


EditAndMore::EditAndMore(QWidget *parent)
    : QWidget{parent}
{
    mainFrame = new QGroupBox(this);
    QHBoxLayout* mainLayout = new QHBoxLayout(this);

    mainFrame->setLayout(mainLayout);
    mainLayout->setSpacing(0);
    mainFrame->setMinimumHeight(33);
    mainFrame->setMinimumWidth(126);
    editBtn = new QPushButton("Edit");
    editBtn->setStyleSheet("border: 1px solid;\n border-color: none rgba(216, 216, 216, 0.18) none none ;");
    moreBtn = new QPushButton("···");

    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->addWidget(editBtn);
    mainLayout->addWidget(moreBtn);
}
