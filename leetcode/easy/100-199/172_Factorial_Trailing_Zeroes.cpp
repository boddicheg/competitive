#include <iostream>
#include <vector>
#include <set>
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

// Trailing 0s in n! = Count of 5s in prime factors of n!
class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5)
            return 0;
        int count = 0;
        while (n >= 5)
        {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.trailingZeroes(100);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
