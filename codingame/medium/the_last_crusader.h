// https://www.codingame.com/ide/puzzle/the-last-crusade-episode-1

#ifndef LASTCRUSADE_H
#define LASTCRUSADE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <cassert>

template<typename T, char D>
std::vector<T> split(const std::string& line)
{
    std::vector<T> elements;
    std::stringstream ss(line);
    std::string item;
    while (std::getline(ss, item, D))
    {
        elements.push_back(std::stoi(item));
    }
    return elements;
}

enum class ERoute
{
    NoRoute,
    Top,
    Bottom,
    Left,
    Right
};

struct SRoute
{
    int id;
    ERoute input;
    ERoute output;
};

class Game
{
public:
    Game()
    {
        routes.push_back({ 1, ERoute::Top, ERoute::Bottom });
        routes.push_back({ 1, ERoute::Left, ERoute::Bottom });
        routes.push_back({ 1, ERoute::Right, ERoute::Bottom });

        routes.push_back({ 2, ERoute::Left, ERoute::Right });
        routes.push_back({ 2, ERoute::Right, ERoute::Left });

        routes.push_back({ 3, ERoute::Top, ERoute::Bottom });

        routes.push_back({ 4, ERoute::Top, ERoute::Left });
        routes.push_back({ 4, ERoute::Right, ERoute::Bottom });

        routes.push_back({ 5, ERoute::Top, ERoute::Right });
        routes.push_back({ 5, ERoute::Left, ERoute::Bottom });

        routes.push_back({ 6, ERoute::Left, ERoute::Right });
        routes.push_back({ 6, ERoute::Right, ERoute::Left });

        routes.push_back({ 7, ERoute::Top, ERoute::Bottom });
        routes.push_back({ 7, ERoute::Right, ERoute::Bottom });

        routes.push_back({ 8, ERoute::Left, ERoute::Bottom });
        routes.push_back({ 8, ERoute::Right, ERoute::Bottom });

        routes.push_back({ 9, ERoute::Top, ERoute::Bottom });
        routes.push_back({ 9, ERoute::Left, ERoute::Bottom });

        routes.push_back({ 10, ERoute::Top, ERoute::Left });

        routes.push_back({ 11, ERoute::Top, ERoute::Right });

        routes.push_back({ 12, ERoute::Right, ERoute::Bottom });

        routes.push_back({ 13, ERoute::Left, ERoute::Bottom });
    }

    ERoute GetRoutes(int id, ERoute input)
    {
        ERoute found = ERoute::NoRoute;
        for(size_t i = 0; i < routes.size(); ++i)
        {
            if((routes.at(i).id == id) && (routes.at(i).input == input))
            {
                found = routes.at(i).output;
                break;
            }
        }
        return found;
    }

    void SetLine(const std::vector<int>& l)
    {
        tunnel.push_back(std::move(l));
    }

    ERoute GetRoute(const std::string& s)
    {
        if(s == "TOP") { return ERoute::Top; }
        if(s == "LEFT") { return ERoute::Left; }
        if(s == "RIGHT") { return ERoute::Right; }
        if(s == "BOTTOM") { return ERoute::Bottom; }
        return ERoute::NoRoute;
    }

    std::string GetRoute(ERoute r)
    {
        if(r == ERoute::Top) { return "TOP"; }
        if(r == ERoute::Left) { return "LEFT"; }
        if(r == ERoute::Right) { return "RIGHT"; }
        if(r == ERoute::Bottom) { return "BOTTOM"; }
        return "NOROUTE";
    }

    void print()
    {
        for(const auto& line: tunnel)
        {
            for(const auto& cell: line)
            {
                std::cerr << cell << " ";
            }
            std::cerr << std::endl;
        }
    }

    void Calculate(int x, int y, const std::string& pos)
    {
        int cell_type = tunnel.at(y).at(x);
        std::cerr << "Cell type is " << cell_type << std::endl;
        ERoute input = GetRoute(pos);
        ERoute possible = GetRoutes(cell_type, input);
        std::cerr << "-> " << GetRoute(possible) << std::endl;
        if(possible == ERoute::Left)
        {
            std::cout << --x << " " << y << std::endl;
        }
        else if (possible == ERoute::Right)
        {
            std::cout << ++x << " " << y << std::endl;
        }
        else if(possible == ERoute::Bottom)
        {
            std::cout << x << " " << ++y << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> tunnel;
    std::vector<SRoute> routes;
};

int main()
{
    Game g;
    int W; // number of columns.
    int H; // number of rows.
    std::cin >> W >> H; std::cin.ignore();
    for (int i = 0; i < H; i++) {
        std::string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        std::getline(std::cin, LINE);av
        auto v = split<int, ' '>(LINE);
        g.SetLine(v);
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    std::cin >> EX; std::cin.ignore();

    g.print();
    // game loop
    while (1) {
        int XI;
        int YI;
        std::string POS;
        std::cin >> XI >> YI >> POS; std::cin.ignore();

        std::cerr << "Position is " << XI << ", " << YI << std::endl;

        g.Calculate(XI, YI, POS);
    }
}

#endif // LASTCRUSADE_H