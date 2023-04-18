#include "mainwindow.h"

#include <QGraphicsScene>
#include "cellitem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_newField_triggered()
{

}

void MainWindow::on_action_closeField_triggered()
{

}

void MainWindow::on_action_Calc_triggered()
{

}

void MainWindow::on_action_CalcPath_triggered()
{

}

