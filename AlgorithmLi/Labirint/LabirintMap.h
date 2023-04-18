#pragma once
#include "BaseField.h"

namespace algo {

	class LabirintMap : public BaseField<bool>
	{
	public:
        LabirintMap(unsigned int width, unsigned int heigth);
        virtual ~LabirintMap() = default;

	};

}
