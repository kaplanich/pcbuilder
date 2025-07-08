#ifndef EDITANDMORE_H
#define EDITANDMORE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class EditAndMore : public QWidget
{
    Q_OBJECT
public:
    explicit EditAndMore(QWidget *parent = nullptr);

private:
    QPushButton* editBtn;
    QPushButton* moreBtn;

signals:
};

#endif // EDITANDMORE_H
