// https://www.codingame.com/ide/puzzle/horse-racing-duals

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::vector<int> strengths;
    std::cin >> N; std::cin.ignore();
    for (int i = 0; i < N; i++)
    {
        int Pi;
        std::cin >> Pi; std::cin.ignore();
        strengths.push_back(Pi);
    }

    std::sort(strengths.begin(), strengths.end());
    int index = -1;
    int min = std::numeric_limits<int>::max();
    if (strengths.size() > 1)
    {
        for (int i = 0; i < N - 1; i++)
        {
            int value = strengths.at(i + 1) - strengths.at(i);
            if (value < min)
            {
                min = value;
                index = i;
            }
        }
        std::cout << min << std::endl;
    }
    else
        std::cout << "0" << std::endl;

}