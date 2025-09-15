#ifndef BUILDEDITDIALOG_H
#define BUILDEDITDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>

namespace Ui {
class BuildEditDialog;
}

class BuildEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuildEditDialog(QWidget *parent = nullptr);
    ~BuildEditDialog();

    QString budget() const;
    QString base() const;
    QString gpu() const;

    void setBudget(const int &value);
    void setBase(const QString &value);
    void setGpu(const QString &value);

private:
    Ui::BuildEditDialog *ui;
};

#endif // BUILDEDITDIALOG_H
