#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small)
    : parking({big, medium, small})
    { }
    
    bool addCar(int carType)
    {
        if (parking[carType - 1] > 0)
        {
            parking[carType - 1]--;
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    std::vector<int> parking;
};


int main(int argc, char const *argv[])
{
    ParkingSystem s;
    auto result = s.template(..);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
