#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString flights[] = {"flight101", "flight102", "flight103"};
    int seats[] = {20, 50, 30};

    QString userFlight = ui->lineEdit->text();
    QString userName = ui->lineEdit_2->text();

    bool find = false;

    for(int i = 0; i < 3; i++){
        if(userFlight == flights[i] && seats[i] > 0){
            QMessageBox::information(this, "Success Message", "User Name: "+userName+"\n" "Flight: "+userFlight+"\n"
                                     "Reserved a seat successfully");
        }
        find = true;
        break;
    }

    if(!find){
        QMessageBox::information(this, "Error Message", "Incorrect flight number of seats unavailable");
    }
}


void MainWindow::on_pushButton_2_clicked()
{

}

