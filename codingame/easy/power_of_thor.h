// https://www.codingame.com/ide/puzzle/power-of-thor-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    std::cin >> lightX >> lightY >> initialTX >> initialTY; std::cin.ignore();

    int thorX = initialTX;
    int thorY = initialTY;
    // game loop
    while (1)
    {
        int remainingTurns;
        std::cin >> remainingTurns; std::cin.ignore();

        std::string directionX;
        std::string directionY;

        if (thorX > lightX)
        {
            directionX += "W";
            thorX -= 1;
        }
        else if (thorX < lightX)
        {
            directionX += "E";
            thorX += 1;
        }

        if (thorY > lightY)
        {
            directionY += "N";
            thorY -= 1;
        }
        else if (thorY < lightY)
        {
            directionY += "S";
            thorY += 1;
        }

        std::cout << directionY << directionX << std::endl; // A single line providing the move to be made: N NE E SE S SW W or NW
    }
}