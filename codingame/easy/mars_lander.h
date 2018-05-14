// https://www.codingame.com/ide/puzzle/mars-lander-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    std::cin >> surfaceN; std::cin.ignore();
    for (int i = 0; i < surfaceN; i++)
    {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        std::cin >> landX >> landY; std::cin.ignore();
    }

    // game loop
    while (1)
    {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        std::cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; std::cin.ignore();

        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).
        int p = 0;
        if (vSpeed < -39)
        {
            p = 3.7;
            //cerr << p << endl;
            std::cout << 0 << " " << 4 << std::endl;
        }
        else
            std::cout << "0 0" << std::endl;
    }
}