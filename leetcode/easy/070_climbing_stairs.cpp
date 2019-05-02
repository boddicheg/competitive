#include <iostream>
#include <vector>
#include <set>
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
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i)
        {
            int fib = first + second;
            first = second;
            second = fib;
        }

        return second;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.climbStairs(10);
    return 0;
}
