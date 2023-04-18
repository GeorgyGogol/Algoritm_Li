#include "pch.h"
#include "Field.h"

#include <algorithm>

algo::Field::Field(unsigned int width, unsigned int height) :
	BaseField<FieldCell>(width, height)
{
}

algo::Field::Field(LabirintMap* pLabirint) :
    BaseField<FieldCell> (pLabirint->getWidth(), pLabirint->getHeight())
{
    FieldCell* pCell;
    for (unsigned int y = 0; y < getHeight(); ++y) {
        for (unsigned int x = 0; x < getWidth(); ++x) {
            pCell = getCell(x, y);
            pCell->setMovable(!pLabirint->getCellValue(x, y));
        }
    }
}

algo::Field::~Field()
{
}

void algo::Field::SetMovePointsToCells(std::vector<Point> cells, int movePoints)
{
    std::vector<Point> neighborCells;

    for (auto coord : cells) {
        getCell(coord.getX(), coord.getY())->setMovePoints(movePoints);

        for (int y = coord.getY() - 1; y < coord.getY() + 1 + 1; ++y) {
            if (!valideY(y)) continue;

            for (int x = coord.getX() - 1; x < coord.getX() + 1 + 1; ++x) {
                if (!valideX(x)) continue;

                if (getCell(x, y)->getMovePoints() >= 0) continue;
                if (!getCell(x, y)->Movable()) continue;


                if (std::find(neighborCells.begin(), neighborCells.end(), Point(x, y)) != neighborCells.end()) continue;

                neighborCells.push_back(Point(x, y));
            }
        }
    }


    if (neighborCells.size() > 0)
        SetMovePointsToCells(neighborCells, movePoints + 1);
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
        for (int y = int(Y) - 1; y < int(Y) + 1 + 1; ++y) {
            if (!valideY(y)) continue;
            for (int x = int(X) - 1; x < int(X) + 1 + 1; ++x) {
                if (!valideX(x)) continue;

				pCell = getCell(x, y);
				if (pCell->getMovePoints() < 0) continue;
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
