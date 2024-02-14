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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::pair<T, T> &p)
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
    int numSpecialEquivGroups(std::vector<std::string> &A)
    {
        std::unordered_set<std::string> result;
        for (const auto &str : A)
        {
            std::pair<std::string, std::string> p;
            for (size_t i = 0; i < str.size(); i++)
            {
                if (i % 2 == 0) p.first += str.at(i);
                else p.second += str.at(i);
            }
            std::sort(p.first.begin(), p.first.end());
            std::sort(p.second.begin(), p.second.end());

            // std::cout << p << std::endl;

            result.insert(p.first + p.second);
        }
        return result.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::string> data = {
        // "a","b","c","a","c","c" // -> ["a","a"], ["b"], ["c","c","c"]
        "aa","bb","ab","ba" // -> ["aa"], ["bb"], ["ab"], ["ba"]
        // "abc", "acb", "bac", "bca", "cab", "cba" // -> ["abc","cba"], ["acb","bca"], ["bac","cab"]
        // "abcd","cdab","adcb","cbad" // -> ["abcd","cdab","adcb","cbad"]
    };
    auto result = s.numSpecialEquivGroups(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
