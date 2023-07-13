#include "pch.h"
#include "FieldCell.h"

algo::FieldCell::FieldCell()
{
}

algo::FieldCell::FieldCell(bool movable) :
	isThereCanMove_(movable)
{
}

bool algo::FieldCell::Movable() const noexcept
{
	return isThereCanMove_;
}

void algo::FieldCell::setMovable(bool canMove) noexcept
{
    isThereCanMove_ = canMove;
}

void algo::FieldCell::setMovePoints(int value)
{
	if (isThereCanMove_)
        MovePoints_ = int8_t(value);
}

int algo::FieldCell::getMovePoints() const noexcept
{
	return MovePoints_;
}

void algo::FieldCell::resetMovePoints() noexcept
{
	if (isThereCanMove_) MovePoints_ = -1;
}

bool algo::FieldCell::isHaveMovePoints() const noexcept
{
    return MovePoints_ > -1;
}

bool algo::FieldCell::isMarked() const noexcept
{
	return Marked_ > 0;
}

void algo::FieldCell::setMarkedState(bool state) noexcept
{
	Marked_ = state ? 1 : 0;
}

int algo::FieldCell::getStatus() const noexcept
{
	int out = -100;
	if (!isThereCanMove_) out = -2;
	else if (MovePoints_ < 0) out = -1;
	else if (Marked_ > 0) out = -3;
	else out = int(MovePoints_);
    return out;
}

