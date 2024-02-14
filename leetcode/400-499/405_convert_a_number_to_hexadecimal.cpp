#include <iostream>
#include <vector>
#include <bitset>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    char tohex(int i)
    {
        if (i < 10)
            return i + '0';
        else
            return i + 87;
    }
    string toHex(int num)
    {
        if (num == 0) return "0";

        std::string result;
        unsigned int unum = 0 ;
        if (num < 0)
            unum = ~(std::abs(num)) + 1;
        else
            unum = num;

        while (unum != 0)
        {
            int r  = unum % 16;
            unum /= 16;
            result.push_back(tohex(r));
        }

        return std::string(result.rbegin(), result.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::cout << s.toHex(0) << std::endl;
    // std::cout << s.toHex(1) << std::endl;
    // std::cout << s.toHex(26) << std::endl;
    // std::cout << s.toHex(3456) << std::endl;
    // std::cout << s.toHex(-1) << std::endl;
    std::cout << s.toHex(-1) << std::endl;
    return 0;
}
