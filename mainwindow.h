#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stackedbudgetbar.h"
#include "buildtypeselection.h"
#include "editandmore.h"
#include "buildeditdialog.h"
#include "componenttile.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_selectTypeBtn_clicked();

    void on_curBuild_clicked();

    void on_myBuild_clicked();

    void on_community_clicked();

    void on_soft_clicked();

    void on_support_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<ComponentTile*> m_tiles;
    StackedBudgetBar *bar;
    EditAndMore *editAndMore;
    int currentBudget = 1000;
    int totalCost;
    QString currentBase;
    QString currentGpu;
};
#endif // MAINWINDOW_H
