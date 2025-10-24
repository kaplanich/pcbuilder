#ifndef ADDCOMPONENTSWINDOW_H
#define ADDCOMPONENTSWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDir>
#include <QSqlTableModel>
#include "libs/componentwidget.h"

namespace Ui {
class AddComponentsWindow;
}

class AddComponentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentsWindow(QWidget *parent = nullptr);
    ~AddComponentsWindow();
    QSqlRecord getSelectedComponent();

private slots:
    void onComponentAdded(const QSqlRecord& record);

private:
    Ui::AddComponentsWindow *ui;
    void connectToDB();
    void showComponents();
    QString readQueryFromFile(const QString& fileName);
    QSqlDatabase db;
    QSqlRecord m_record;
};

#endif // ADDCOMPONENTSWINDOW_H
