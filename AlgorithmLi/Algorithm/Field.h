#pragma once

#include "BaseField.h"
#include "FieldCell.h"
#include "LabirintMap.h"

#include <vector>
#include "Point.h"

namespace algo {

	class Field : public BaseField<FieldCell>
	{
	public:
        Field(unsigned int width, unsigned int height);
        Field(LabirintMap* pLabirint);
        virtual ~Field();

    private:
        void SetMovePointsToCells(std::vector<Point> cells, int movePoints);

	public:
		int getCellStatus(unsigned int x, unsigned int y) const;

		void calcFieldFrom(unsigned int x, unsigned int y);
        void calcFieldTo(int x, int y);
	};

}
