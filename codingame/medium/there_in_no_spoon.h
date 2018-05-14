// https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{

    int width; // the number of cells on the X axis
    std::cin >> width; std::cin.ignore();
    int height; // the number of cells on the Y axis
    std::cin >> height; std::cin.ignore();
    std::cerr << "W: " << width << std::endl;
    std::cerr << "H: " << height << std::endl;

    std::vector<std::vector<bool>> matrix(height + 1, std::vector<bool>(width + 1, false));

    for (int i = 0; i < height; i++)
    {
        std::string line; // width characters, each either 0 or .
        std::getline(std::cin, line);
        std::cerr << "H: " << i << " = " << line << std::endl;
        for (size_t j = 0; j < line.size(); j++)
        {
            if (line.at(j) == '0')
                matrix.at(i).at(j) = true;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (!matrix.at(i).at(j))
                continue;
            std::string output(std::to_string(j) + " " + std::to_string(i) + " ");
            // Right neighbor
            int shiftR = 1;
            bool foundedR = false;
            while (j + shiftR < matrix.at(i).size())
            {
                if (matrix.at(i).at(j + shiftR))
                {
                    output += std::to_string(j + shiftR) + " " + std::to_string(i) + " ";
                    foundedR = true;
                    break;
                }
                else
                    shiftR++;
            }
            if (!foundedR)
                output += "-1 -1 ";

            // Bottom
            int shiftB = 1;
            bool foundedB = false;
            while (i + shiftB < matrix.size())
            {
                if (matrix.at(i + shiftB).at(j))
                {
                    output += std::to_string(j) + " " + std::to_string(i + shiftB) + " ";
                    foundedB = true;
                    break;
                }
                else
                    shiftB++;
            }
            if (!foundedB)
                output += "-1 -1 ";

            std::cout << output << std::endl;
        }
    }
}