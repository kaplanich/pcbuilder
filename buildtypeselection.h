#ifndef BUILDTYPESELECTION_H
#define BUILDTYPESELECTION_H

#include <QDialog>

namespace Ui {
class BuildTypeSelection;
}

class BuildTypeSelection : public QDialog
{
    Q_OBJECT

public:
    explicit BuildTypeSelection(QWidget *parent = nullptr);
    ~BuildTypeSelection();
    QString typeLetter();

private slots:
    void on_gamingTypeBtn_clicked();

    void on_officeTypeBtn_clicked();

    void on_serverTypeBtn_clicked();

private:
    Ui::BuildTypeSelection *ui;
    std::string typeLetterText;
};

#endif // BUILDTYPESELECTION_H
