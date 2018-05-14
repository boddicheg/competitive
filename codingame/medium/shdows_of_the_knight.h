// https://www.codingame.com/ide/puzzle/shadows-of-the-knight-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct bounds
{
    int ulx;
    int uly;
    int drx;
    int dry;
};

std::ostream &operator << (std::ostream &o, const bounds &b)
{
    o << "[ (" << b.ulx << ", " << b.uly << "), (" << b.drx  << ", " << b.dry << ") ]" << std::endl;
    return o;
}

inline std::pair<int, int> mid(const bounds &b)
{
    return std::move(
               std::make_pair(
                   (b.drx + b.ulx) / 2,
                   (b.dry + b.uly) / 2
               )
           );
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    std::cin >> W >> H; std::cin.ignore();
    int N; // maximum number of turns before game over.
    std::cin >> N; std::cin.ignore();
    int X0;
    int Y0;
    std::cin >> X0 >> Y0; std::cin.ignore();

    int firstX = 0;
    int firstY = 0;
    int lastX = W - 1;
    int lastY = H - 1;

    bounds b = { 0, 0, lastX, lastY };

    std::cerr << "Initial bound: " << b << std::endl;

    int x = X0;
    int y = Y0;

    // game loop
    while (1)
    {
        std::string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        std::cin >> bombDir; std::cin.ignore();

        std::cerr << "Direction: " << bombDir << std::endl;

        if (bombDir == "L")
        {
            b = { firstX, y, x - 1, y };
        }
        if (bombDir == "R")
        {
            b = { x + 1, y, lastX, y };
        }
        if (bombDir == "U")
        {
            b = { x, firstY, x, y - 1 };
        }
        if (bombDir == "D")
        {
            b = { x, y + 1, x, lastY };
        }

        if (bombDir == "UL")
        {
            b = { firstX, firstY, x - 1, y - 1 };
        }
        if (bombDir == "UR")
        {
            b = { x + 1, firstY, lastX, y - 1 };
        }
        if (bombDir == "DR")
        {
            b = { x + 1, y + 1, lastX, lastY };
        }
        if (bombDir == "DL")
        {
            b = { firstX, y + 1, x - 1, lastY };
        }

        std::cerr << "Current bound: " << b << std::endl;

        auto m = mid(b);

        std::cout << m.first << " " << m.second << std::endl; // the location of the next window Batman should jump to.

        x = m.first;
        y = m.second;

        firstX = b.ulx;
        firstY = b.uly;
        lastX = b.drx;
        lastY = b.dry;

    }
}