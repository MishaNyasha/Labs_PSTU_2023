#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstdlib>
#include <QLabel>
#include <QMap>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QLabel *labelNumberOfDay;
    QLabel *labelAmountOfMoney;
    QLabel *LabelDeadField_1;
    QLabel *LabelDeadField_2;
    QLabel *LabelDeadField_3;
    QLabel *LabelDeadField_4;
    QLabel *LabelDeadField_5;
    QLabel *LabelDeadField_6;
private slots:
    void StartTheGame();
    void AddWaterInSupply(int amount);
    void TakeWaterFromSupply(int amount);
    void WaterTheField(int num);
    void FieldDrought(int amount);
    void NEXTDAY();
    void updateDayNumber();
    void PayTime();
    void CheckTime();
    void UpdateBalance(int balance);

    void on_buttonWaterTheField_clicked();
    void on_buttonNextDay_clicked();
    void on_buttonWaterAllFields_clicked();
    void on_buttonBuy10Water_clicked();
    void on_buttonBuy25Water_clicked();
    void on_pushButtonToRestart_clicked();    
private:
    QMap<QString, QLabel*> labelMap;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
