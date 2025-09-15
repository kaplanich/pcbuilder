#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    std::vector<Component> comp = {
        {"GeForce RTX 4080 SUPER", 2030, "GPU"},
        {"AMD Ryzen 7 7800X3D", 400, "CPU"},
        {"MSI MPG B650 EDGE", 257, "Motherboard"},
        {"NZXT H7", 150, "Case"},
        {"Corsair 32GB DDR5", 200, "RAM"}
    };

    ui->setupUi(this);

    on_curBuild_clicked();

    bar = new StackedBudgetBar(comp);
    editAndMore = new EditAndMore();

    ui->scrollArea_2->setStyleSheet("QScrollBar:handle { background-color: rgb(64, 64, 64);} QScrollBar:horizontal { background-color: rgb(100, 100, 100); }");

    ui->greenCostBar->layout()->addWidget(bar);
    ui->editAndMoreBtns->layout()->addWidget(editAndMore);


    for(int i = 0; i < comp.size(); ++i) {
        ComponentTile* cmp = new ComponentTile(comp[i], i, this);
        connect(cmp, &ComponentTile::clicked, bar, &StackedBudgetBar::setSelectedIndex);
        ui->horizontalLayout_10->addWidget(cmp, 0, Qt::AlignLeading);
        m_tiles.push_back(cmp);
    }


    for (auto tile : m_tiles) {
        connect(tile, &ComponentTile::tileSelected, this, [this](ComponentTile* selectedTile){
            for (auto t : m_tiles) {
                t->setSelected(t == selectedTile);
            }
        });
    }

    connect(editAndMore->editBtn, &QPushButton::clicked, this, [this]() {
        BuildEditDialog dlg(this);
        dlg.setBudget(currentBudget);
        dlg.setBase(currentBase);
        dlg.setGpu(currentGpu);
        if (dlg.exec() == QDialog::Accepted) {
            currentBudget = dlg.budget().toInt();
            currentBase   = dlg.base();
            currentGpu    = dlg.gpu();

            if(currentBudget == ' ' || currentBudget < 0) currentBudget = 0;

            ui->label_5->setText("$" + QString::number(currentBudget));
            ui->label_6->setText(currentBase);
            ui->label_8->setText(currentGpu);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_selectTypeBtn_clicked()
{
    BuildTypeSelection buildType;
    buildType.setModal(true);
    if(buildType.exec()) {
        ui->selectTypeBtn->setText(buildType.typeLetter());
    }
}


void MainWindow::on_curBuild_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#curBuild {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(82,82,82);}");
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_community_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#community {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(82,82,82);}");
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_support_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#support {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(82,82,82);}");
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_soft_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#soft {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(82,82,82);}");
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_myBuild_clicked()
{
    ui->NavButtons->setStyleSheet("QPushButton {border-radius: 12px;color: rgba(240, 240, 240, 0.7);} \n QPushButton#myBuild {color: rgb(255,255,255);background-color: rgb(42,42,42);} \n QPushButton:hover{background-color: rgb(82,82,82);}");
    ui->stackedWidget->setCurrentIndex(4);
}







