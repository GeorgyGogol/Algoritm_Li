#pragma once

#include <cstdint>

namespace algo {

	class FieldCell
	{
	public:
		FieldCell();
		FieldCell(bool movable);

	private:
		bool isThereCanMove_ = true;
		std::int8_t MovePoints_ = -1;
		std::int8_t Marked_ = -1;

	public:
		bool Movable() const noexcept;
        void setMovable(bool canMove) noexcept;

		void setMovePoints(int value);
		int getMovePoints() const noexcept;
		void resetMovePoints() noexcept;

		bool isMarked() const noexcept;
		void setMarkedState(bool state = true) noexcept;

		int getStatus() const noexcept;

	};

}

