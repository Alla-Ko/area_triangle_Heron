
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <cmath>
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
    double area_Heron (double a,double b,double c);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    double st_a,st_b,st_c;
    double result=0.00;
};

#endif // MAINWINDOW_H
