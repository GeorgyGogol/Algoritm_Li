#include "pch.h"
#include "LabirintMap.h"

//#include <stdlib>
#include <random>
#include <time.h>

algo::LabirintMap::LabirintMap(unsigned int width, unsigned int heigth) :
    BaseField<bool>(width, heigth)
{
    std::srand(time(nullptr));

    for (unsigned int Y = 0; Y < getHeight(); ++Y) {
        if (Y == 0 || Y == getWidth() - 1) {
            for (unsigned int X = 0; X < getWidth(); ++X) {
                setCell(X, Y, false);
            }
            continue;
        }

        if (Y % 2 == 1) {
            for (unsigned int X = 0; X < getWidth(); ++X) {
                setCell(X, Y, rand() % 100 < 75);
            }
            continue;
        }

        for (unsigned int X = 0; X < getWidth(); ++X) {
            setCell(X, Y, false);
        }

    }
}

