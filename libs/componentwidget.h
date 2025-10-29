#ifndef COMPONENTWIDGET_H
#define COMPONENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>
#include <QSqlRecord>
#include <QPushButton>
#include <QPainter>
#include "ImageCache.h"

class ComponentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ComponentWidget(const QSqlRecord& record, QWidget* parent = nullptr);

private:
    QHBoxLayout* layout;
    QSqlRecord m_record;
    void on_add_clicked();
    void addField(QHBoxLayout* layout, const QSqlRecord& record, const QString& fieldName);
    void addGPUField(QHBoxLayout* layout, const QSqlRecord& record);
    void addCPUField(QHBoxLayout* layout, const QSqlRecord& record);
    void addRAMField(QHBoxLayout* layout, const QSqlRecord& record);
    void addPSUField(QHBoxLayout* layout, const QSqlRecord& record);
    void addStorageField(QHBoxLayout* layout, const QSqlRecord& record);
    void addCoolingField(QHBoxLayout* layout, const QSqlRecord& record);
    void addMotherboardField(QHBoxLayout* layout, const QSqlRecord& record);
    void addCaseField(QHBoxLayout* layout, const QSqlRecord& record);
    void paintEvent(QPaintEvent *e);

signals:
    void componentAdded(const QSqlRecord& record);
};

#endif // COMPONENTWIDGET_H
