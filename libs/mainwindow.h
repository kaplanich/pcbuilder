#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlrecord>
#include "./libs/stackedbudgetbar.h"
#include "./forms/buildtypeselection.h"
#include "./libs/editandmore.h"
#include "./forms/buildeditdialog.h"
#include "./libs/componenttile.h"
#include "./forms/addcomponentswindow.h"
#include "./libs/ComponentsLib.h"
#include "./libs/componentfactory.h"
#include "./libs/build.h"

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

    void registerAll();

private slots:

    void BuildEditDialogInvoke();

    void refreshTiles();

    void refreshCost();

    void on_selectTypeBtn_clicked();

    void on_curBuild_clicked();

    void on_myBuild_clicked();

    void on_community_clicked();

    void on_soft_clicked();

    void on_support_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Component> comp;
    std::vector<ComponentTile*> m_tiles;
    Build* build;
    StackedBudgetBar *bar;
    EditAndMore *editAndMore;
    int currentBudget = 1000;
    int totalCost;
    QString currentBase;
    QString currentGpu;
};
#endif // MAINWINDOW_H
