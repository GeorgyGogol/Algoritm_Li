#include "pch.h"
#include "LabirintMap.h"

#include <random>
#include <time.h>

algo::LabirintMap::LabirintMap(unsigned int width, unsigned int heigth) :
    BaseField<bool>(width, heigth)
{
    for (unsigned int y = 0; y < getHeight(); ++y)
        for (unsigned int x = 0; x < getWidth(); ++x) {
            setCell(x, y, false);
        }
}

void algo::LabirintMap::Generate(const LabirintSettings& settings) noexcept
{
    std::srand(time(nullptr));

    for (unsigned int Y = 0; Y < getHeight(); ++Y) {
        if (Y == 0 || Y == getHeight() - 1) {
            for (unsigned int X = 0; X < getWidth(); ++X) {
                setCell(X, Y, false);
            }
            continue;
        }

        if (Y % 2 == 1) {
            for (unsigned int X = 0; X < getWidth(); ++X) {
                setCell(X, Y, rand() % 100 < settings.AvalMovPercent);
            }
            continue;
        }

        for (unsigned int X = 0; X < getWidth(); ++X) {
            setCell(X, Y, false);
        }

    }
}

void algo::LabirintMap::SetMovableState(unsigned int x, unsigned int y, bool canMove)
{
    setCell(x, y, canMove);
}

#pragma region Операторы вывода в поток
std::ostream& operator<<(std::ostream& out, algo::LabirintMap& map)
{
    out << map.getHeight() << map.getWidth() << "\n";
    for (int y = 0; y < map.getHeight(); ++y) {
        for (int x = 0; x < map.getWidth(); ++x) {
            out << map.getCellValue(x, y);
        }
        out << "\n";
    }
    out << "\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, algo::LabirintMap* map)
{
    out << map->getHeight() << map->getWidth() << "\n";
    for (int y = 0; y < map->getHeight(); ++y) {
        for (int x = 0; x < map->getWidth(); ++x) {
            out << map->getCellValue(x, y);
        }
        out << "\n";
    }
    out << "\n";
    return out;
}

#pragma endregion

