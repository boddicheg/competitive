#include <iostream>
#include <vector>
#include <map>
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
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};

        std::vector<std::string> table = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        std::vector<string> result;
        result.push_back("");

        for (const auto &e : digits)
        {
            std::string letters = table[e - '0'];
            vector<std::string> tmp;
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < letters.size(); ++j)
                    tmp.push_back(result.at(i) + letters.at(j));
            }
            result.swap(tmp);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.letterCombinations("3");
    print(result);
    return 0;
}
