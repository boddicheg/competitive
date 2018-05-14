// https://www.codingame.com/ide/puzzle/ascii-art

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
    int L;
    std::cin >> L; std::cin.ignore();
    int H;
    std::cin >> H; std::cin.ignore();
    std::string T;
    std::getline(std::cin, T);
    std::vector<std::string> lines;
    for (int i = 0; i < H; i++)
    {
        std::string ROW;
        std::getline(std::cin, ROW);
        lines.push_back(ROW);
    }
    int aCode = 'A';
    int zCode = 'Z';
    std::string result;
    for (size_t j = 0; j < lines.size(); j++)
    {
        for (size_t i = 0; i < T.size(); i++)
        {
            int letterCode = (int) T.at(i);
            int startPos = -1;
            if (letterCode < aCode)
                startPos = (zCode - aCode + 1) * L;
            else
            {
                letterCode = (int) std::toupper(T.at(i));
                startPos = (letterCode - aCode) * L;
            }
            std::string part = lines[j].substr(startPos, L);
            result.append(part);
        }
        result.append("\n");
    }

    std::cout << result << std::endl;
}