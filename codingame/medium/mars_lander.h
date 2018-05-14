// https://www.codingame.com/ide/puzzle/mars-lander-episode-2

#ifndef MARS_LANDER_2_H
#define MARS_LANDER_2_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

constexpr double PI = 3.141592653589793;
constexpr double G = 3.711;
constexpr int HS_LIMIT = 20;
constexpr int VS_LIMIT = 40;

inline double ToDegrees(double radians)
{
    return (radians * 180.0 / PI);
}

class Game
{
private:
    // Ground
    int startX;
    int endX;
    int height;

    std::vector<std::pair<int, int>> land;

    // lander
    int x;
    int y;
    int dx; // horisontal speed
    int dy; // vertical speed

public:
    void SetGroundPoint(int x, int y)
    {
        land.push_back({ x, y });
    }

    void CalculateFlat()
    {
        for (size_t i = 1; i < land.size(); ++i)
        {
            if (land.at(i - 1).second == land.at(i).second)
            {
                height = land.at(i - 1).second;
                startX = land.at(i - 1).first;
                endX = land.at(i).first;
            }
        }
    }

    bool IsOnFlat() const
    {
        return (startX <= x) && (x <= endX);
    }

    void CurrentTurn(int _x, int _y, int _dx, int _dy)
    {
        x = _x;
        y = _y;
        dx = _dx;
        dy = _dy;
    }

    int AngleToSlowLander()
    {
        // Calculate
        double speed_vector = std::sqrt(dx * dx + dy * dy);
        double angle = std::asin((double)dx / speed_vector);
        return (int) ToDegrees(angle);
    }

    int AngleForManeuver()
    {
        int angle = (int) ToDegrees(std::acos(G / 4.0));
        // Left of target
        if (x < startX)
            return -angle;
        else if (endX < x)
            return angle;
        else
            return 0;
    }

    bool TooFastHorisontally()
    {
        return std::abs(dx) > 4 * HS_LIMIT;
    }

    bool TooSlowHorisontally()
    {
        return std::abs(dx) < 2 * HS_LIMIT;
    }

    bool WrongDirection()
    {
        return (x < startX && dx < 0) || (x > endX && dx > 0);
    }

    bool SafeSpeed()
    {
        return (std::abs(dx) <= (HS_LIMIT - 5)) && (std::abs(dy) <= (VS_LIMIT - 5));
    }

    bool Finished()
    {
        return  y < height + 20;
    }
};


int main()
{
    Game game;
    int surfaceN; // the number of points used to draw the surface of Mars.
    std::cin >> surfaceN; std::cin.ignore();
    for (int i = 0; i < surfaceN; i++)
    {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        std::cin >> landX >> landY; std::cin.ignore();
        game.SetGroundPoint(landX, landY);
    }

    game.CalculateFlat();

    // game loop
    while (1)
    {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        std::cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; std::cin.ignore();

        game.CurrentTurn(X, Y, hSpeed, vSpeed);

        if (!game.IsOnFlat())
        {
            // Compensate angle if ship has wrong direction or too fast
            if (game.WrongDirection() || game.TooFastHorisontally())
                std::cout << game.AngleToSlowLander() << " 4" << std::endl;
            // Slighty move to target flat
            else if (game.TooSlowHorisontally())
                std::cout << game.AngleForManeuver() << " 4" << std::endl;
            else
                std::cout << "0 " << (vSpeed >= 0 ? 3 : 4) << std::endl;
        }
        else
        {
            if (game.Finished())
                std::cout << "0 3" << std::endl;
            else if (game.SafeSpeed())
                std::cout << "0 2" << std::endl;
            else
                std::cout << game.AngleToSlowLander() << " 4" << std::endl;

        }
    }
}

#endif // MARS_LANDER_2_H