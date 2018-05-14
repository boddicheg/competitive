// https://www.codingame.com/ide/puzzle/defibrillators

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cmath>

double PI()
{
    return 3.141592653589793238462;
}

struct defibrillator
{
    std::string desc;
    double lat;
    double lng;

    double dist(double _lat, double _lng)
    {
        double x = (lng - _lng) * PI() / 180 * cos((_lat * PI() / 180 + lat * PI() / 180) / 2.0);
        double y = (lat - _lat) * PI() / 180;
        return sqrt(x * x + y * y) * 6371000.0;
    }
};

double convert(std::string num)
{
    size_t index = num.find_last_of(",");
    num.replace(index, 1, ".");
    double converted = std::stod(num.c_str());
    return converted;
}

void split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
        elems.push_back(item);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    std::string LON;
    std::cin >> LON; std::cin.ignore();
    std::string LAT;
    std::cin >> LAT; std::cin.ignore();
    int N;
    std::cin >> N; std::cin.ignore();
    std::cerr << LON << " " << LAT << std::endl;
    std::vector<defibrillator> defs;
    for (int i = 0; i < N; i++)
    {
        std::string DEFIB;
        std::getline(std::cin, DEFIB);
        std::vector<std::string> tokens;
        split(DEFIB, ';', tokens);
        defibrillator d =
        {
            tokens.at(1),
            convert(tokens.at(4)),
            convert(tokens.at(5))
        };
        defs.push_back(d);
    }

    int index = -1;
    double min = std::numeric_limits<double>::max();
    for (int i = 0; i < defs.size(); i++)
    {
        auto defib = defs.at(i);
        auto current = defib.dist(convert(LON), convert(LAT));
        if ( current < min)
        {
            min = current;
            index = i;
        }
    }

    std::cout << defs.at(index).desc << std::endl;
}