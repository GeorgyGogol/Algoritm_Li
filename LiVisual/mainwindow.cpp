#include "mainwindow.h"

#include <QGraphicsScene>
#include "cellitem.h"
#include "LabirintMap.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
	pField(nullptr)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
	delete pField;
	pField = nullptr;
}

void MainWindow::on_action_newField_triggered()
{
	CreateField(11, 11);
	ui->statusBar->UpdateFieldSize(11, 11);
}

void MainWindow::on_action_closeField_triggered()
{
	DeleteField();
	ui->statusBar->ResetFieldSize();
}

void MainWindow::on_action_Calc_triggered()
{
	if (!pField) return;

	pField->calcFieldFrom(0, 0);
	ui->gv_Main->scene()->update();
}

void MainWindow::on_action_CalcPath_triggered()
{
	if (!pField) return;

	pField->calcFieldFrom(0, 0);
	pField->calcFieldTo(pField->getWidth() - 2, pField->getHeight() - 1);

	ui->gv_Main->scene()->update();
}

void MainWindow::CreateField(int width, int height)
{
	if (pField) return;
	
	using namespace algo;

	std::unique_ptr<LabirintMap> map(new LabirintMap(width, height));

	pField = new algo::Field(map.get());

	QGraphicsScene* pScene = new QGraphicsScene(this);

	CellItem* pCell;
	for (int y = 0; y < pField->getHeight(); ++y) {
		for (int x = 0; x < pField->getWidth(); ++x) {
			pCell = new CellItem(pField->getCell(x, y));
			pCell->setX(pCell->boundingRect().width() * x);
			pCell->setY(pCell->boundingRect().height() * y);
			pScene->addItem(pCell);
		}
	}
	
	ui->gv_Main->setScene(pScene);

}

void MainWindow::DeleteField()
{
	if (!pField) return;

	delete ui->gv_Main->scene();
	ui->gv_Main->setScene(nullptr);

	delete pField;
	pField = nullptr;
}

