#include "pch.h"
#include "Field.h"

#include "LabirintMap.h"
#include "Point.h"
#include "RangeController.h"

#include <algorithm>

algo::Field::Field(unsigned int width, unsigned int height) :
	BaseField<FieldCell>(width, height),
    LocalRange(new serv::RangeController(width, height))
{
}

algo::Field::Field(LabirintMap* pLabirint) :
    BaseField<FieldCell> (pLabirint->getWidth(), pLabirint->getHeight()),
    LocalRange(new serv::RangeController(pLabirint->getWidth(), pLabirint->getHeight()))
{
    for (unsigned int y = 0; y < getHeight(); ++y) {
        for (unsigned int x = 0; x < getWidth(); ++x) {
            getCell(x, y)->setMovable(!pLabirint->getCellValue(x, y));
        }
    }
}

algo::Field::~Field()
{
    delete LocalRange;
}

void algo::Field::SetMovePointsToCells(std::vector<Point>& cells, unsigned int movePoints)
{
    std::vector<Point>* neighborCells = new std::vector<Point>;

    for (Point coord : cells) {
        getCell(coord.getX(), coord.getY())->setMovePoints(movePoints);
    }

    for (Point coord : cells) {
        LocalRange->SetCurrentPosition(coord.getX(), coord.getY());

        for (int y = LocalRange->getMinY(); y < LocalRange->getMaxY(); ++y) {
            for (int x = LocalRange->getMinX(); x < LocalRange->getMaxX(); ++x) {
                if (getCell(x, y)->notMovable()) continue;
                if (getCell(x, y)->isHaveMovePoints()) continue;
                if (std::find(neighborCells->begin(), neighborCells->end(), Point(x, y)) != neighborCells->end()) continue;

                neighborCells->push_back(Point(x, y));
            }
        }
    }

    cells = *neighborCells;
    delete neighborCells;

    if (cells.size() > 0) {
        SetMovePointsToCells(cells, movePoints + 1);
    }
}

int algo::Field::getCellStatus(unsigned int x, unsigned int y) const
{
	return getCell(x, y)->getStatus();
}

void algo::Field::calcFieldFrom(unsigned int X, unsigned int Y)
{
	if (!checkCoordinate(X, Y)) throw 1;

    std::vector<Point> startCell;
    startCell.push_back(Point(X, Y));

    SetMovePointsToCells(startCell, 0);
}

void algo::Field::calcFieldTo(int X, int Y)
{
	if (!checkCoordinate(X, Y)) throw 1;

    getCell(X, Y)->setMarkedState();
	int localMin = getCell(X, Y)->getMovePoints();
	if (localMin < 1) throw 2;

    int minX = X, minY = Y;
	FieldCell* pCell;
	while (localMin > 0)
	{
        LocalRange->SetCurrentPosition(X, Y);

        for (int y = LocalRange->getMinY(); y < LocalRange->getMaxY(); ++y) {
            for (int x = LocalRange->getMinX(); x < LocalRange->getMaxX(); ++x) {
				pCell = getCell(x, y);

				if (!pCell->isHaveMovePoints()) continue;

				if (pCell->getMovePoints() < localMin) {
					localMin = pCell->getMovePoints();
					minX = x;
					minY = y;
				}
			}
		}

		X = minX;
		Y = minY;
		getCell(X, Y)->setMarkedState();
	}

}
