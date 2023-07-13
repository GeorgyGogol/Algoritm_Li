#pragma once

#include "BaseField.h"
#include "FieldCell.h"

#include <vector>


namespace algo {

    class LabirintMap;
    class Point;

    namespace serv {
        class RangeController;
    }

	class Field : public BaseField<FieldCell>
	{
	public:
        Field(unsigned int width, unsigned int height);
        Field(LabirintMap* pLabirint);
        virtual ~Field();

    private:
        serv::RangeController* LocalRange;

        void SetMovePointsToCells(std::vector<Point>& cells, unsigned int movePoints);

	public:
		int getCellStatus(unsigned int x, unsigned int y) const;

		void calcFieldFrom(unsigned int x, unsigned int y);
        void calcFieldTo(int x, int y);
	};

}
