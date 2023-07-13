#include <iostream>
#include <iomanip>

#include "LabirintMap.h"
#include "Field.h"

using namespace std;
using namespace algo;

void printLabirint(algo::LabirintMap* pMap);
void printFieldPoints(algo::Field* pField);
void printFieldTrack(algo::Field* f);


int main()
{
	LabirintMap* map = new LabirintMap(10, 11);
    algo::LabirintSettings set;
    set.AvalMovPercent = 50;

    map->Generate(set);

    //printLabirint(map);

	algo::Field* field = new algo::Field(map);

    printFieldPoints(field);
    
    system("pause");
    system("cls");

    field->calcFieldFrom(1, 0);

    printFieldPoints(field);

    system("pause");
    //system("cls");

    field->calcFieldTo(8, 10);

    printFieldTrack(field);

    system("pause");


	cout << endl;
	return 0;
}

void printLabirint(algo::LabirintMap* labirint)
{
    cout << "Labirint " 
        << labirint->getWidth() 
        << "x" 
        << labirint->getHeight() 
        << endl;

    cout << '\t';
    for (unsigned int x = 0; x < labirint->getWidth(); ++x) {
        cout << setw(2) << setfill('0') << x;
    }
    cout << endl << endl;

	for (unsigned int y = 0; y < labirint->getHeight(); ++y) {
        cout << y << '\t';

		for (unsigned int x = 0; x < labirint->getWidth(); ++x) {

			if (labirint->getCellValue(x, y))
				cout << char(178) << char(178);
			else
				cout << char(176) << char(176);

		}
		cout << endl;
	}
	cout << endl;
}

void printFieldPoints(algo::Field* f)
{
    cout << "Field "
        << f->getWidth()
        << "x"
        << f->getHeight()
        << endl;

    cout << '\t';
    for (unsigned int x = 0; x < f->getWidth(); ++x) {
        cout << setw(2) << setfill('0') << x;
    }
    cout << endl << endl;

	int state;
	for (unsigned int y = 0; y < f->getHeight(); ++y) {
        cout << y << '\t';

		for (unsigned int x = 0; x < f->getWidth(); ++x) {
			//cout.width(2);

			state = f->getCellStatus(x, y);

			switch (state)
			{
			case -2:
                cout << char(178) << char(178);
				break;

			case -1:
                cout << char(176) << char(176);
				break;

			default:
                cout << setw(2) << setfill('0') << state;
				break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void printFieldTrack(algo::Field* f)
{
    for (unsigned int y = 0; y < f->getHeight(); ++y) {
        for (unsigned int x = 0; x < f->getWidth(); ++x) {
            //cout.width(1);

            if (f->getCell(x, y)->isMarked())
                cout << char(178) << char(178);
            else
                cout << char(176) << char(176);

        }
        cout << endl;
    }
    cout << endl;
}

