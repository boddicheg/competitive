// https://www.codingame.com/ide/puzzle/stock-exchange-losses

#ifndef STOCKEXCHANGE_H
#define STOCKEXCHANGE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// #define DEBUG
//#define EXAMPLE1
//#define EXAMPLE2
// #define EXAMPLE3
//#define EXAMPLE4

typedef std::pair<int, int> streak;

int main()
{

#ifndef DEBUG
    int n;
    std::vector<int> seq;
    std::cin >> n; std::cin.ignore();
    std::cerr << "N = " << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        int v;

        std::cin >> v; std::cin.ignore();
        std::cerr << v << " " ;
        seq.push_back(v);
    }
    std::cerr << std::endl;
#endif

#ifdef EXAMPLE1
    std::vector<int> seq = { 10, 6, 8, 4, 6, 2 };
#endif

#ifdef EXAMPLE2
    std::vector<int> seq = { 0, 5, 3, 4, 2, 3 };
#endif

#ifdef EXAMPLE3
    std::vector<int> seq = { 5, 3, 4, 2, 3, 1 };
#endif

#ifdef EXAMPLE4
    std::vector<int> seq = { 1, 5, 4, 10, 8, 4 , 5, 42, 41};
#endif
    std::vector<streak> streaks;

    int currentMax = seq.at(0);
    int currentMin = seq.at(0);
    int potentialMin = seq.at(0);
    int currentStreak = 0;

    for (size_t i = 1; i < seq.size(); ++i)
    {
        int element = seq.at(i);
        if (currentMax > element)
        {
            currentStreak++;
            currentMin = element;
            if (element < potentialMin)
                potentialMin = element;
        }
        else
        {
            streaks.push_back(std::make_pair(currentMax, (currentMin < potentialMin && currentStreak != 0) ? currentMin : potentialMin));
            currentMax = element;
            currentMin = element;
            potentialMin = element;
            currentStreak = 0;
        }

        std::cerr << "Curent max " << currentMax
                  << ", curent min " << currentMin
                  << ", current streak " << currentStreak
                  << ", potential min " << potentialMin << std::endl;
    }

    int maxLoss = 0;
    for (const auto &p : streaks)
    {
        std::cerr << "-> " << p.first << " - " << p.second << std::endl;
        if ((p.second - p.first) < maxLoss)
            maxLoss = p.second - p.first;
    }

    if (streaks.empty())
        std::cout << currentMin - currentMax << std::endl; else
        std::cout << maxLoss << std::endl;

}

#endif // STOCKEXCHANGE_H