#include <iostream>
#include <vector>
#include <cmath>
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
    bool judgeSquareSum(int c)
    {
        long long r = (int)std::sqrt(c);

        int l = 0;
        while (l <= r)
        {
            long long value = l * l + r * r;
            // std::cout << i << "^2 + " << first << "^2 = "  << value  << "(" << c << ")" << std::endl;
            if (value < (long long)c)
                l++;
            else if (value > (long long)c)
                r--;
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.judgeSquareSum(2147483646) << std::endl;
    std::cout << std::boolalpha << s.judgeSquareSum(1) << std::endl;
    std::cout << std::boolalpha << s.judgeSquareSum(26) << std::endl;
    return 0;
}
