#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::vector<int> fairCandySwap(std::vector<int> &A, std::vector<int> &B)
    {
        int sumA = 0;
        for (const auto &e: A)
            sumA += e;

        int sumB = 0;
        for (const auto &e: B)
            sumB += e;
        // if alice wants to exchange x
        // we should chech if Bob can exchange
        // y = x - (sumB - sumA) / 2
        int delta = (sumB - sumA) / 2.0; 

        std::unordered_set<int> cacheB;
        for (const auto &e: B)
            cacheB.insert(e);

        for (const auto &e: A)
            if ( cacheB.find(e + delta) != cacheB.end())
                return { e, e + delta};
        return { };
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> A {
        1, 1
    };
    std::vector<int> B {
        2, 2
    };
    auto result = s.fairCandySwap(A, B);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
