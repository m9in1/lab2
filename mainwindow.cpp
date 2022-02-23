#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <csvreader.h>
#include <QString>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    csvreader csv("D:/MIET/OOP/lab2/lab2/datebase.csv");
    if(csv.is_open()){

        lessons = csv.readall();

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchLes(){
    for(const auto &l: lessons){
        if(l.lesname==ui->input->text()){
            ui->output->append(l.lesname+", "+QString::number(l.lesaud)+", "+l.type_of_les+";");
            //
        }
    }
}
