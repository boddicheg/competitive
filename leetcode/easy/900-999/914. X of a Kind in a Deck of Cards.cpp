#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

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

class Solution {
public:
    int gcd(int x, int y)
    {
        return (x == 0) ? y : gcd(y % x, y);
    }

    bool hasGroupsSizeX(vector<int>& deck) {
        std::map<int, int> mapped;

        for(auto &&d: deck)
            mapped[d] ++;
        
        int divider = -1;
        for(auto &&e: mapped)
        {
            if (divider == -1)
                divider = e.second;
            else
                divider = gcd(divider, e.second);
        }

        return divider >= 2;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {1,1,2,2,2,2};
    auto result = s.hasGroupsSizeX(v);
    std::cout << s.gcd(6,4);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
