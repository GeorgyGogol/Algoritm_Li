#pragma once

namespace algo {

	template<class TyFieldCell>
	class BaseField
	{
	public:
		BaseField(unsigned int width, unsigned int height) :
			Width_(width), Heigth_(height)
		{
			Map_ = new TyFieldCell * [Heigth_];
			for (unsigned int y = 0; y < Heigth_; ++y) {
				Map_[y] = new TyFieldCell[Width_];
			}
		}

        ~BaseField()
		{
			for (unsigned int y = 0; y < Heigth_; ++y) {
				delete[] Map_[y];
			}
			delete[] Map_;
		}

	private:
        unsigned int Width_, Heigth_;
		TyFieldCell** Map_;

	protected:
		bool checkCoordinate(unsigned int x, unsigned int y) const
		{
            if (x >= Width_) return false;
            if (y >= Heigth_) return false;
			return true;
		}

        bool checkCoordinate(int x, int y) const
        {
            if (x < 0) return false;
            if (y < 0) return  false;
            if (x >= int(Width_)) return false;
            if (y >= int(Heigth_)) return false;
            return true;
        }

        bool valideX(int X) {
            return X > -1 && X < int(Width_);
        }

        bool valideY(int Y) {
            return Y > -1 && Y < int(Heigth_);
        }

	public:
        unsigned int getWidth() const noexcept { return Width_; }
        unsigned int getHeight() const noexcept { return Heigth_; }

		TyFieldCell* getCell(unsigned int x, unsigned int y) const
		{
			if (!checkCoordinate(x, y)) throw 1;
			return &Map_[y][x];
		}

        TyFieldCell* getCell(int x, int y) const
        {
            if (!checkCoordinate(x, y)) throw 1;
            return &Map_[y][x];
        }

        virtual TyFieldCell getCellValue(unsigned int x, unsigned int y) const
        {
            if (!checkCoordinate(x, y)) throw 1;
            return Map_[y][x];
        }

        void setCell(unsigned int x, unsigned int y, TyFieldCell cell)
        {
            if (!checkCoordinate(x, y)) throw 1;
            Map_[y][x] = cell;
        }
	};
}

