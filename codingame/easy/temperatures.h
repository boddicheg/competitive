// https://www.codingame.com/ide/puzzle/temperatures

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

int main()
{
    int n; // the number of temperatures to analyse
    std::cin >> n; std::cin.ignore();
    std::string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    std::getline(std::cin, temps);

    std::stringstream ss(temps);
    int real = 5527;
    int positive = 0;
    int min = 5527;
    while (ss >> positive)
    {
        if (std::abs(positive) < min)
        {
            min = std::abs(positive);
            real = positive;
        }
        if (std::abs(real) == std::abs(positive))
            real = (real == positive) ? real : std::abs(real);
    }

    std::cout << ((real == 5527) ? 0 : real ) << std::endl;
}