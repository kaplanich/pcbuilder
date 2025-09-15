#ifndef EDITANDMORE_H
#define EDITANDMORE_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGroupBox>

class EditAndMore : public QWidget
{
    Q_OBJECT
public:
    explicit EditAndMore(QWidget *parent = nullptr);
    QGroupBox* mainFrame;
    QPushButton* editBtn;
    QPushButton* moreBtn;

signals:
};

#endif // EDITANDMORE_H
