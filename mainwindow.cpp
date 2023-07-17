
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression myReg("(^(-)?)(([1-9]{1}[0-9]{0,6}((\\.){1}[0-9]{1,6})?)|(0\\.[0-9]{1,6}))");
    QValidator *myvalidator=new QRegularExpressionValidator(myReg,this);
    ui->lineEdit_A->setValidator(myvalidator);
    ui->lineEdit_B->setValidator(myvalidator);
    ui->lineEdit_C->setValidator(myvalidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::area_Heron (double a,double b,double c)
    {
    if(a<=0)throw "Сторона a повинна бути більше 0";
    if(b<=0)throw "Сторона b повинна бути більше 0";
    if(c<=0)throw "Сторона c повинна бути більше 0";
    if(a+b<=c)throw "Сторона c повинна бути менша за суму інших сторін, такий трикутник не існує!";
    if(a+c<=b)throw "Сторона b повинна бути менша за суму інших сторін, такий трикутник не існує!";
    if(c+b<=a)throw "Сторона a повинна бути менша за суму інших сторін, такий трикутник не існує!";
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
    }


void MainWindow::on_pushButton_clicked()
{
    try
    {
        st_a=ui->lineEdit_A->text().toDouble();
        st_b=ui->lineEdit_B->text().toDouble();
        st_c=ui->lineEdit_C->text().toDouble();

        result=area_Heron(st_a,st_b,st_c);
        ui->lineEdit_res->setText( QString::number(result));
    }

    catch (const char*a) {
        QMessageBox::critical(this, "Помилка, внесіть коректні дані!",a);
    }
}


