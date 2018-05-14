// https://www.codingame.com/ide/puzzle/conway-sequence

#ifndef CONWEYSEQ_H
#define CONWEYSEQ_H

#include <string>
#include <iostream>
#include <sstream>

std::string LookAndSay(const std::string &s)
{
    std::string result;
    std::stringstream s_stream(s);

    int current;
    s_stream >> current;
    int count = 1;

    int element;

    while (s_stream >> element)
    {
        if (element == current)
            count++;
        else
        {
            result += std::to_string(count) + " " + std::to_string(current) + " ";
            current = element;
            count = 1;
        }
    }
    result += std::to_string(count) + " " + std::to_string(current);
    return result;
}

int main()
{
    int R;
    std::cin >> R; std::cin.ignore();
    int L;
    std::cin >> L; std::cin.ignore();

    std::string row = std::to_string(R);
    for (int i = 1; i < L; i++)
        row = LookAndSay(row);

    std::cout << row << std::endl;

    return 0;
}

#endif // CONWEYSEQ_H