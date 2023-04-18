#pragma once

#include <QMainWindow>
#include "ui_mainwindow.h"

#include "Field.h"

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

	void CreateField(int width, int height);

private:
    Ui::MainWindow *ui;
	algo::Field* pField;

	void DeleteField();

};

