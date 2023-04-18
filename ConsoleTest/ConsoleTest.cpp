#include <iostream>
#include <iomanip>

#include "LabirintMap.h"
#include "Field.h"

using namespace std;
using namespace algo;


void print(algo::Field* f)
{
	int state;
	for (unsigned int y = 0; y < f->getHeight(); ++y) {
		for (unsigned int x = 0; x < f->getWidth(); ++x) {
			cout.width(3);

			state = f->getCellStatus(x, y);

			switch (state)
			{
			case -2:
				cout << char(178);
				break;

			case -1:
				cout << char(176);
				break;

			default:
				cout << state;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void print2(algo::Field* f)
{
	for (unsigned int y = 0; y < f->getHeight(); ++y) {
		for (unsigned int x = 0; x < f->getWidth(); ++x) {
			//cout.width(1);

			if (f->getCell(x, y)->isMarked())
				cout << char(178);
			else
				cout << char(176);

		}
		cout << endl;
	}
	cout << endl;
}

void print(LabirintMap* labirint)
{
	for (unsigned int y = 0; y < labirint->getHeight(); ++y) {
		for (unsigned int x = 0; x < labirint->getWidth(); ++x) {
			cout.width(1);

			if (labirint->getCellValue(x, y))
				cout << char(178);
			else
				cout << char(176);

		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	LabirintMap* map = new LabirintMap(10, 10);

	//print(map);

	algo::Field* f = new algo::Field(map);
	//algo::Field* f = new algo::Field(7, 7);
	print(f);

	f->calcFieldFrom(0, 0);
	print(f);

	try {
		f->calcFieldTo(9, 9);
		print2(f);
	}
	catch (int) {
		cout << "Cannot find path..." << endl;
	}


	cout << endl;
	return 0;
}
