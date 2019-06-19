#include <iostream>
#include <vector>
#include <map>
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
    bool isAlienSorted(std::vector<std::string> &words, std::string order)
    {
        int table[26];
        for (size_t i = 0; i < order.size(); i++)
            table[order.at(i) - 'a'] = i;

        for (size_t i = 0; i < words.size() - 1; i++)
        {
            std::string &s1 = words.at(i);
            std::string &s2 = words.at(i + 1);
            bool is_compare_size = true;
            for (size_t i = 0; i < std::min(s1.size(), s2.size()); i++)
            {
                if (s1.at(i) != s2.at(i))
                {
                    if (table[s1.at(i) - 'a'] > table[s2.at(i) - 'a'])
                        return false;
                    is_compare_size = false;
                    break;
                }
            }

            if (s2.size() < s1.size() && is_compare_size)
                return false;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<std::string> words = {
    //     "hello", "leetcode"
    // };
    // std::string order = "hlabcdefgijkmnopqrstuvwxyz";

    // std::vector<std::string> words = {
    //    "word","world","row"
    // };
    // std::string order = "worldabcefghijkmnpqstuvxyz";

    std::vector<std::string> words = {
        "apple", "app"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";

    auto result = s.isAlienSorted(words, order);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
