#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StartTheGame();
    labelNumberOfDay = ui->labelNumberOfDay;
    labelAmountOfMoney = ui->labelAmountOfMoney;
    LabelDeadField_1 = ui->LabelDeadField_1;
    LabelDeadField_2 = ui->LabelDeadField_2;
    LabelDeadField_3 = ui->LabelDeadField_3;
    LabelDeadField_4 = ui->LabelDeadField_4;
    LabelDeadField_5 = ui->LabelDeadField_5;
    LabelDeadField_6 = ui->LabelDeadField_6;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::StartTheGame()
{
    ui->progressBar_WaterSupply->setValue(100);
    ui->progressBar_1field->setValue(100);
    ui->progressBar_2field->setValue(100);
    ui->progressBar_3field->setValue(100);
    ui->progressBar_4field->setValue(100);
    ui->progressBar_5field->setValue(100);
    ui->progressBar_6field->setValue(100);
    ui->labelNumberOfDay->clear();
    ui->labelAmountOfMoney->clear();
    ui->LabelDeadField_1->clear();
    ui->LabelDeadField_2->clear();
    ui->LabelDeadField_3->clear();
    ui->LabelDeadField_4->clear();
    ui->LabelDeadField_5->clear();
    ui->LabelDeadField_6->clear();
    ui->pushButtonToRestart->hide();
}
void MainWindow::AddWaterInSupply(int amount)
{
    int currentValue = ui->progressBar_WaterSupply->value();
    ui->progressBar_WaterSupply->setValue(qMin(currentValue + amount, ui->progressBar_WaterSupply->maximum()));
}
void MainWindow::TakeWaterFromSupply(int amount)
{
    int currentValue = ui->progressBar_WaterSupply->value();
    ui->progressBar_WaterSupply->setValue(qMax(currentValue - amount, 0));
}
void MainWindow::WaterTheField(int num)
{
    switch (num)
    {
    case 1:
        if(ui->progressBar_1field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_1field->setValue(qMin(ui->progressBar_1field->value() + 10, ui->progressBar_1field->maximum()));
        break;
    case 2:
        if(ui->progressBar_2field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_2field->setValue(qMin(ui->progressBar_2field->value() + 10, ui->progressBar_2field->maximum()));
        break;
    case 3:
        if(ui->progressBar_3field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_3field->setValue(qMin(ui->progressBar_3field->value() + 10, ui->progressBar_3field->maximum()));
        break;
    case 4:
        if(ui->progressBar_4field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_4field->setValue(qMin(ui->progressBar_4field->value() + 10, ui->progressBar_4field->maximum()));
        break;
    case 5:
        if(ui->progressBar_5field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_5field->setValue(qMin(ui->progressBar_5field->value() + 10, ui->progressBar_5field->maximum()));
        break;
    case 6:
        if(ui->progressBar_6field->value() == 0 || ui->progressBar_WaterSupply->value()< 2)
        {
            ui->statusbar->showMessage("Полить поле невозможно!");
            return;
        }
        TakeWaterFromSupply(2);
        ui->progressBar_6field->setValue(qMin(ui->progressBar_6field->value() + 10, ui->progressBar_6field->maximum()));
        break;
    default:
        ui->statusbar->showMessage("Укажите корректный номер поля (1 - 6)!");
        break;
    }
}
void MainWindow::on_buttonWaterTheField_clicked()
{
    if(ui->progressBar_WaterSupply->value() == 0)
    {
        ui->statusbar->showMessage("запасы воды закончились!");
        return;
    }
    QString Number = ui->lineEdit_NumberOfField->text();
    int num = Number.toInt();
    WaterTheField(num);
}
void MainWindow::on_buttonWaterAllFields_clicked()
{
    WaterTheField(1);
    WaterTheField(2);
    WaterTheField(3);
    WaterTheField(4);
    WaterTheField(5);
    WaterTheField(6);
    ui->statusbar->showMessage("Все живые поля были политы!");
}
void MainWindow::FieldDrought(int amount)
{
    ui->progressBar_1field->setValue(qMax(ui->progressBar_1field->value() - (amount+rand()%10), 0));
    ui->progressBar_2field->setValue(qMax(ui->progressBar_2field->value() - (amount+rand()%10), 0));
    ui->progressBar_3field->setValue(qMax(ui->progressBar_3field->value() - (amount+rand()%10), 0));
    ui->progressBar_4field->setValue(qMax(ui->progressBar_4field->value() - (amount+rand()%10), 0));
    ui->progressBar_5field->setValue(qMax(ui->progressBar_5field->value() - (amount+rand()%10), 0));
    ui->progressBar_6field->setValue(qMax(ui->progressBar_6field->value() - (amount+rand()%10), 0));
}
void MainWindow::CheckTime()
{
    bool anyFieldAlive = false;
    if (ui->progressBar_1field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_1->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_1->setPixmap(scaledPixmap);
    }
    if (ui->progressBar_2field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_2->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_2->setPixmap(scaledPixmap);
    }
    if (ui->progressBar_3field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_3->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_3->setPixmap(scaledPixmap);
    }
    if (ui->progressBar_4field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_4->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_4->setPixmap(scaledPixmap);
    }
    if (ui->progressBar_5field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_5->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_5->setPixmap(scaledPixmap);
    }
    if (ui->progressBar_6field->value() > 0) {anyFieldAlive = true;}
    else {
        QPixmap pixmap(":/image/img/WASTED.png");
        QSize labelSize = ui->LabelDeadField_6->size();
        QPixmap scaledPixmap = pixmap.scaled(labelSize, Qt::KeepAspectRatio);
        ui->LabelDeadField_6->setPixmap(scaledPixmap);
    }
    if (!anyFieldAlive)
    {
        QMessageBox::critical(this, "Смерть", "Вся рассада погибла");
        ui->pushButtonToRestart->show();
    }
}
void MainWindow::PayTime()
{
    QString Day = labelNumberOfDay->text();
    int day = Day.toInt();
    if((day % 7) == 0)
    {
        QString Balance = labelAmountOfMoney->text();
        int balance = Balance.toInt();
        if(ui->progressBar_1field->value() != 0){balance += 50;}
        if(ui->progressBar_2field->value() != 0){balance += 50;}
        if(ui->progressBar_3field->value() != 0){balance += 50;}
        if(ui->progressBar_4field->value() != 0){balance += 50;}
        if(ui->progressBar_5field->value() != 0){balance += 50;}
        if(ui->progressBar_6field->value() != 0){balance += 50;}
        UpdateBalance(balance);
    }
}
void MainWindow::NEXTDAY()
{
    updateDayNumber();
    PayTime();
    FieldDrought(rand()%10);
    CheckTime();
}
void MainWindow::updateDayNumber()
{
    QString text = labelNumberOfDay->text();
    int value = text.toInt();
    ++value;
    labelNumberOfDay->setText(QString::number(value));
    QFont font = labelNumberOfDay->font();
    font.setPointSize(12);
    labelNumberOfDay->setFont(font);
    labelNumberOfDay->setStyleSheet("color: #aa5500;");
}
void MainWindow::on_buttonNextDay_clicked()
{
    NEXTDAY();
}
void MainWindow::UpdateBalance(int balance)
{
    labelAmountOfMoney->setText(QString::number(balance));
    QFont font = labelAmountOfMoney->font();
    font.setPointSize(12);
    labelAmountOfMoney->setFont(font);
    labelAmountOfMoney->setStyleSheet("color: #55aa00;");
}
void MainWindow::on_buttonBuy10Water_clicked()
{
    QString Balance = labelAmountOfMoney->text();
    int balance = Balance.toInt();
    if(balance >= 45)
    {
        AddWaterInSupply(10);
        balance -= 45;
        UpdateBalance(balance);
    }
}
void MainWindow::on_buttonBuy25Water_clicked()
{
    QString Balance = labelAmountOfMoney->text();
    int balance = Balance.toInt();
    if(balance >= 100)
    {
        AddWaterInSupply(25);
        balance -= 100;
        UpdateBalance(balance);
    }
}
void MainWindow::on_pushButtonToRestart_clicked()
{
    StartTheGame();
}
