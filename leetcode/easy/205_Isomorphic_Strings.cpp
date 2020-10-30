#include <iostream>
#include <vector>
#include <map>
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

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::vector<int> sv(128, -1);
        std::vector<int> tv(128, -1);
        for (size_t i = 0; i < s.size(); i++)
        {
            if (sv[s.at(i)] != tv[t.at(i)])
                return false;
            sv[s.at(i)] = i;
            tv[t.at(i)] = i;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.isIsomorphic("egg", "add");
    auto result1 = s.isIsomorphic("foo", "bar");
    auto result2 = s.isIsomorphic("paper", "titlr");
    auto result3 = s.isIsomorphic("ab", "aa");
    std::cout << "Result: " << result << std::endl;
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "Result: " << result3 << std::endl;
    return 0;
}
