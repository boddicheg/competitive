// https://www.codingame.com/ide/puzzle/the-gift

#ifndef THEGIFT_H
#define THEGIFT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Game
{
public:
    Game(int _cost)
        : cost(_cost)
    {}

    void Contribute(int c)
    {
        contribs.push_back(c);
    }

    int Sum()
    {
        return std::accumulate(contribs.begin(), contribs.end(), 0);
    }

    bool Imposible()
    {
        return Sum() < cost;
    }

    void Calculate()
    {
        std::vector<int> results;
        std::sort(contribs.begin(), contribs.end());

        for (size_t i = 0; i < contribs.size(); ++i)
        {
            int avg = cost / (contribs.size() - i);
            if (contribs.at(i) >= avg)
            {
                results.push_back(avg);
                cost -= avg;
            }
            else
            {
                results.push_back(contribs.at(i));
                cost -= contribs.at(i);
            }
        }

        if (cost != 0)
            results.at(results.size() - 1) += cost;
        for (const auto &item : results)
            std::cout << item << std::endl;
    }

private:
    int cost;
    std::vector<int> contribs;
};

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    int C;
    std::cin >> C; std::cin.ignore();

    Game game(C);
    for (int i = 0; i < N; i++)
    {
        int B;
        std::cin >> B; std::cin.ignore();
        game.Contribute(B);
    }

    if (game.Imposible())
        std::cout << "IMPOSSIBLE" << std::endl;
    else
        game.Calculate();

}

#endif // THEGIFT_H