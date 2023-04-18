#pragma once

namespace algo {

    class Point
    {
    public:
        Point(int x, int y);
        Point(unsigned int x, unsigned int y);

        bool operator==(const Point& right) const noexcept;

    private:
        int X, Y;

    public:
        int getX() const;

        int getY() const;

    };

}

