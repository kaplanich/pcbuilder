#include "libs/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    on_curBuild_clicked();

    registerAll();

    build = new Build();
    bar = new StackedBudgetBar();
    editAndMore = new EditAndMore();
    ui->scrollArea_2->setStyleSheet("QScrollBar:handle { background-color: rgb(64, 64, 64);} QScrollBar:horizontal { background-color: rgb(100, 100, 100); }");

    ui->greenCostBar->layout()->addWidget(bar);
    ui->editAndMoreBtns->layout()->addWidget(editAndMore);

    connect(editAndMore->editBtn, &QPushButton::clicked, this, &MainWindow::BuildEditDialogInvoke);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectTypeBtn_clicked()
{
    BuildTypeSelection buildType(this);
    buildType.setModal(true);
    if(buildType.exec()) {
        ui->selectTypeBtn->setText(buildType.typeLetter());
    }
}

void MainWindow::refreshTiles()
{
    QLayoutItem *item;
    while ((item = ui->horizontalLayout_10->takeAt(0)) != nullptr) {
        if (item->widget())
            delete item->widget();
    }

    delete item;

    m_tiles.clear();

    int i = 0;

    for (auto& c: build->getAllComponents()) {

        if(c.second.name().isEmpty()) continue;
        ComponentTile* tile = new ComponentTile(c.second, i, this);

        connect(tile, &ComponentTile::clicked, bar, &StackedBudgetBar::setSelectedIndex);

        connect(tile, &ComponentTile::tileSelected, this, [this, tile] {
            for (auto* t : m_tiles)
                t->setSelected(t == tile);
        });

        ui->horizontalLayout_10->addWidget(tile, 0);
        ui->horizontalLayout_10->setAlignment(Qt::AlignLeft);
        m_tiles.push_back(tile);
        ++i;
    }
}

void MainWindow::BuildEditDialogInvoke()
{
    BuildEditDialog dlg(this);
    dlg.setBudget(currentBudget);
    dlg.setBase(currentBase);
    dlg.setGpu(currentGpu);
    if (dlg.exec() == QDialog::Accepted) {
        currentBudget = dlg.budget().toInt();
        currentBase   = dlg.base();
        currentGpu    = dlg.gpu();

        if(currentBudget < 0) currentBudget = 0;

        ui->label_5->setText("$" + QString::number(currentBudget));
        ui->label_6->setText(currentBase);
        ui->label_8->setText(currentGpu);
        refreshCost();
    }
}


void MainWindow::refreshCost()
{
    ui->label_10->setText('$' + QString::number(build->getTotalCost()));
    ui->label_14->setText('$' + QString::number(build->getTotalCost()));

    int diff = ui->label_5->text().remove(0,1).toInt() - build->getTotalCost();

    QString diffLbl = -diff < 0? "-$" + QString::number(diff) : "+$" + QString::number(-diff);
    ui->label_11->setText(diffLbl);
}

void MainWindow::on_pushButton_4_clicked()
{
    AddComponentsWindow addComp(this);
    addComp.setModal(true);
    if(addComp.exec()) {
        QSqlRecord rec = addComp.getSelectedComponent();
        Component* component = ComponentFactory::instance().create(rec);
        build->addComponent(*component);
        qDebug() << build->getTotalCost();
        bar->setComponents(build->getAllComponents());
        refreshCost();
        refreshTiles();
    }
}

void MainWindow::registerAll()
{
    auto& factory = ComponentFactory::instance();
    factory.registerType<Processor>("cpu");
    factory.registerType<GraphicCard>("gpu");
    factory.registerType<Ram>("ram");
    factory.registerType<Motherboard>("motherboard");
    factory.registerType<Storage>("storage");
    factory.registerType<CoolingSystem>("cooling");
    factory.registerType<Case>("case");
    factory.registerType<Psu>("psu");
}


void MainWindow::on_curBuild_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#curBuild {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(42,42,42);}");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_community_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#community {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(42,42,42);}");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_support_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#support {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(42,42,42);}");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_soft_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#soft {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(42,42,42);}");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_myBuild_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#myBuild {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(42,42,42);}");
    ui->stackedWidget->setCurrentIndex(4);
}

