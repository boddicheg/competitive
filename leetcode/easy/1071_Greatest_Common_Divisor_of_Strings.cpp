#include <iostream>
#include <vector>
#include <set>
#include <numeric>

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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::string gcdOfStrings(std::string str1, std::string str2)
    {
        int offset = gcd(str1.size(), str2.size());
        std::string s1(str1.begin(), str1.begin() + offset);
        std::string s2(str2.begin(), str2.begin() + offset);
        return (s1 == s2) ? s1 : "";
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.gcdOfStrings("ABCABC", "ABC");
    // auto result = s.gcdOfStrings("ABABAB", "ABAB");
    auto result = s.gcdOfStrings("LEET", "CODE");
    // auto result = s.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXX", "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
