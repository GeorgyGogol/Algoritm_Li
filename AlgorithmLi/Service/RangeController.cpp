#include "pch.h"
#include "RangeController.h"

algo::serv::RangeController::RangeController(unsigned int Width, unsigned int Height) :
    Width_(Width), Height_(Height)
{
}

int algo::serv::RangeController::MinFrom(int num)
{
    int out = num - 1;
    if (out < 0) out = 0;
    return out;
}

int algo::serv::RangeController::MaxFrom(int num, int max)
{
    int out = num + 2;
    if (out > max) out = max;
    return out;
}

void algo::serv::RangeController::SetCurrentPosition(int x, int y)
{
    y_min = MinFrom(y);
    y_max = MaxFrom(y, Height_);

    x_min = MinFrom(x);
    x_max = MaxFrom(x, Width_);

}
