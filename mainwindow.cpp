#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "course.h"
#include <QMessageBox>
#include <QTableWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addco_clicked()
{
    c[counter].Name=ui->lineEdit_coname->text();
    c[counter].Code = ui->lineEdit_cocode->text();;
    c[counter].Lecture_Hall =ui->lineEdit_colec->text();;
    c[counter].Time =ui->lineEdit_cotime->text();;
    counter++;
    QMessageBox::information(this," ","Course Added");

}


void MainWindow::on_pushButton_searchco_clicked()
{

       for (int i = 0; i < counter; i++) {
           QString name ,code,hall,time;

           if (ui->lineEdit_searchco->text() == c[i].Code) {
                ui->tableWidget->insertColumn(0);
                ui->tableWidget->insertRow(0);
                ui->tableWidget->insertRow(1);
                ui->tableWidget->insertRow(2);
                ui->tableWidget->insertRow(3);

                QTableWidgetItem * item;
                item = new QTableWidgetItem(c[i].Name);
                ui->tableWidget->setItem(0,0,item);

                item = new QTableWidgetItem(c[i].Code);
                ui->tableWidget->setItem(1,0,item);

                item = new QTableWidgetItem(c[i].Lecture_Hall);
                ui->tableWidget->setItem(2,0,item);

                item = new QTableWidgetItem(c[i].Time);
                ui->tableWidget->setItem(3,0,item);




           }
           else
               QMessageBox::information(this," ","Course doesn't exist");
}
}
