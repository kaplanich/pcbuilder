#include "buildeditdialog.h"
#include "ui_buildeditdialog.h"
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QLabel>

BuildEditDialog::BuildEditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BuildEditDialog)
{
    ui->setupUi(this);
    setWindowTitle("Edit Menu");
}

BuildEditDialog::~BuildEditDialog()
{
    delete ui;
}


QString BuildEditDialog::budget() const { return ui->lineEdit->text(); }
QString BuildEditDialog::base() const { return ui->comboBox->currentText(); }
QString BuildEditDialog::gpu() const { return ui->comboBox_2->currentText(); }


void BuildEditDialog::setBudget(const int &value) { ui->lineEdit->setText(QString::number(value)); }
void BuildEditDialog::setBase(const QString &value) { ui->comboBox->setCurrentText(value); }
void BuildEditDialog::setGpu(const QString &value) { ui->comboBox_2->setCurrentText(value); }
