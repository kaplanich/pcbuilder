#include "addcomponentswindow.h"
#include "ui_addcomponentswindow.h"

AddComponentsWindow::AddComponentsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddComponentsWindow)
{
    ui->setupUi(this);
    setWindowTitle("Add Components");

    showComponents();
}

AddComponentsWindow::~AddComponentsWindow()
{
    delete ui;
}


void AddComponentsWindow::connectToDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath() + "/pcbuilder.db");


    if (!db.open()) {
        qDebug() << "Error:" << db.lastError().text();
    } else {
        qDebug() << "Success!";
    }
}

void AddComponentsWindow::showComponents() {
    connectToDB();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    QSqlQuery query(db);
    QString queryStr = readQueryFromFile(":/db/resources/db/request.sql");

    query.prepare(queryStr);
    query.exec(queryStr);
    model->setQuery(queryStr, db);

    while (query.next()) {
        ComponentWidget* widget = new ComponentWidget(query.record());
        ui->componentsList->layout()->addWidget(widget);

        connect(widget, &ComponentWidget::componentAdded, this, &AddComponentsWindow::onComponentAdded);
    }
    qDebug() << model->rowCount();
    db.close();
}


QString AddComponentsWindow::readQueryFromFile(const QString& fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open SQL file:" << fileName;
        return "";
    }
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString sql = in.readAll();
    file.close();

    return sql;
}

void AddComponentsWindow::onComponentAdded(const QSqlRecord& record) {
    m_record = record;
    accept();
}

QSqlRecord AddComponentsWindow::getSelectedComponent() {
    return m_record;
}
