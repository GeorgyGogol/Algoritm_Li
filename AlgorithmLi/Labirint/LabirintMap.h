#pragma once
#include "BaseField.h"
#include <ostream>

namespace algo {

    struct LabirintSettings
    {
        int AvalMovPercent;
    };

	class LabirintMap : public BaseField<bool>
	{
	public:
        LabirintMap(unsigned int width, unsigned int heigth);
        virtual ~LabirintMap() = default;

    public:
        void Generate(const LabirintSettings& settings) noexcept;
        void SetMovableState(unsigned int x, unsigned int y, bool canMove);

	};

}

std::ostream& operator<<(std::ostream& out, algo::LabirintMap& map);

std::ostream& operator<<(std::ostream& out, algo::LabirintMap* map);

