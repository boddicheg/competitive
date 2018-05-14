// https://www.codingame.com/ide/puzzle/onboarding

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * CodinGame planet is being attacked by slimy insectoid aliens.
 * <---
 * Hint:To protect the planet, you can implement the pseudo-code provided in the statement, below the player.
 **/
int main()
{
    while (1)
    {
        string enemy1; // name of enemy 1
        std::cin >> enemy1; std::cin.ignore();
        int dist1; // distance to enemy 1
        std::cin >> dist1; std::cin.ignore();
        string enemy2; // name of enemy 2
        std::cin >> enemy2; std::cin.ignore();
        int dist2; // distance to enemy 2
        std::cin >> dist2; std::cin.ignore();

        if (dist1 < dist2)
            std::cout << enemy1 << std::endl;
        else
            std::cout << enemy2 << std::endl;
    }
}