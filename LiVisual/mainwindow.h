#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
	void on_action_newField_triggered();
	void on_action_closeField_triggered();
	void on_action_Calc_triggered();
	void on_action_CalcPath_triggered();


private:
    Ui::MainWindow *ui;

};

