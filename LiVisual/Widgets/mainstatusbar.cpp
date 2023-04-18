#include "mainstatusbar.h"

MainStatusBar::MainStatusBar(QWidget *parent) :
    QStatusBar(parent),
    FieldSize(std::make_unique<QLabel>(new QLabel(this)))
{
    addWidget(FieldSize.get());

    ResetFieldSize();
}

void MainStatusBar::UpdateFieldSize(int width, int height)
{
    QString text =
            "Размер поля: " +
            QString::number(width) +
            "x" +
            QString::number(height);
    FieldSize->setText(text);
}

void MainStatusBar::ResetFieldSize()
{
    FieldSize->setText("Поле не загружено");
}
