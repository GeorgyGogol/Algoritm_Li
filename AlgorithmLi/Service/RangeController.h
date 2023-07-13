#pragma once

#include "BaseField.h"

namespace algo {

    namespace serv {

        class RangeController
        {
        public:
            RangeController(unsigned int Width, unsigned int Height);

        private:
            unsigned int Width_;
            unsigned int Height_;
            
            //int X, Y;
            int y_min, y_max;
            int x_min, x_max;

            int MinFrom(int num);
            int MaxFrom(int num, int max);

        public:
            void SetCurrentPosition(int x, int y);

            inline int getMinX() const noexcept { return x_min; }
            inline int getMinY() const noexcept { return y_min; }
            inline int getMaxX() const noexcept { return x_max; }
            inline int getMaxY() const noexcept { return y_max; }
        
        };

    }

}

