#include "buildtypeselection.h"
#include "ui_buildtypeselection.h"

BuildTypeSelection::BuildTypeSelection(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BuildTypeSelection)
{
    ui->setupUi(this);
    setWindowTitle("Choose the build type");
}

BuildTypeSelection::~BuildTypeSelection()
{
    delete ui;
}

QString BuildTypeSelection::typeLetter()
{
    return QString::fromStdString(typeLetterText);
}

void BuildTypeSelection::on_gamingTypeBtn_clicked()
{
    typeLetterText = "G";
    accept();
}


void BuildTypeSelection::on_officeTypeBtn_clicked()
{
    typeLetterText = "O";
    accept();
}


void BuildTypeSelection::on_serverTypeBtn_clicked()
{
    typeLetterText = "S";
    accept();
}
