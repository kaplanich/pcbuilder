#include "libs/componentwidget.h"

ComponentWidget::ComponentWidget(const QSqlRecord& record, QWidget* parent) : m_record(record) {
    layout = new QHBoxLayout(this);
    QString type = record.value("type").toString();
    QPushButton* add = new QPushButton("+",this);
    QPushButton* more = new QPushButton("More info",this);
    QLabel* img = new QLabel(this);

    img->setPixmap(record.value("Image").toString());
    img->setFixedSize(60,60);
    img->setScaledContents(true);
    add->setFixedSize(40,40);
    more->setFixedSize(60,40);
    layout->stretch(1);

    layout->addWidget(add);
    layout->addWidget(img);
    layout->addWidget(new QLabel(record.value("Name").toString()));
    layout->addWidget(new QLabel(QString::number(record.value("Price").toDouble()) + '$'));

    if (type == "cpu") addCPUField(layout, record);
    if (type == "gpu") addGPUField(layout, record);
    if (type == "ram") addRAMField(layout, record);
    if (type == "motherboard") addMotherboardField(layout, record);
    if (type == "storage") addStorageField(layout, record);
    if (type == "cooling")  addCoolingField(layout, record);
    if (type == "case")  addCaseField(layout, record);
    if (type == "psu")  addPSUField(layout, record);

    layout->addWidget(more);
    connect(add, &QPushButton::clicked, this, &ComponentWidget::on_add_clicked);
}


void ComponentWidget::addField(QHBoxLayout* layout, const QSqlRecord& record, const QString& fieldName) {
    if (record.contains(fieldName) && !record.value(fieldName).isNull()) {
        layout->addWidget(new QLabel(fieldName + ": " + record.value(fieldName).toString()));
    }
}

void ComponentWidget::addCPUField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "CPU Cores");
    addField(layout, record, "CPU Threads");
    addField(layout, record, "CPU Base Clock (GHz)");
    addField(layout, record, "CPU Boost Clock (GHz)");
    addField(layout, record, "CPU TDP (W)");
}

void ComponentWidget::addGPUField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "GPU Memory (GB)");
    addField(layout, record, "GPU Core Frequency (MHz)");
    addField(layout, record, "GPU TDP (W)");
    addField(layout, record, "GPU Interface");
}

void ComponentWidget::addRAMField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "RAM Capacity (GB)");
    addField(layout, record, "RAM Speed (MHz)");
    addField(layout, record, "RAM Type");
    addField(layout, record, "RAM Modules");
}

void ComponentWidget::addPSUField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "PSU Wattage (W)");
    addField(layout, record, "PSU Efficiency");
    addField(layout, record, "PSU Modular");
}

void ComponentWidget::addStorageField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "Storage Capacity (GB)");
    addField(layout, record, "Storage Type");
    addField(layout, record, "Storage Interface");
    addField(layout, record, "Storage Read Speed (MB/s)");
    addField(layout, record, "Storage Write Speed (MB/s)");
}

void ComponentWidget::addCaseField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "Case Form Factor");
    addField(layout, record, "Case Color");
    addField(layout, record, "Case Material");
    addField(layout, record, "Case Fans Included");
    addField(layout, record, "Case Max GPU Length (mm)");
}

void ComponentWidget::addCoolingField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "Cooling Type");
    addField(layout, record, "Cooling Noise Level (dB)");
    addField(layout, record, "Cooling Radiator Size (mm)");
    addField(layout, record, "Cooling Fan Count");
}

void ComponentWidget::addMotherboardField(QHBoxLayout* layout, const QSqlRecord& record) {
    addField(layout, record, "Motherboard Socket");
    addField(layout, record, "Motherboard Chipset");
    addField(layout, record, "Motherboard Form Factor");
    addField(layout, record, "Motherboard RAM Slots");
    addField(layout, record, "Motherboard Max RAM (GB)");
}


void ComponentWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setPen(QColor::fromRgb(24, 24,24));
    painter.drawRoundedRect(0,5,width()-5, height()-7,3,3);

    QWidget::paintEvent(e);
}

void ComponentWidget::on_add_clicked() {
    emit componentAdded(m_record);
}
