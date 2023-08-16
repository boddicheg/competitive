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
    int findJudge(int N, std::vector<std::vector<int>> &trust)
    {
        std::map<int, int> table;
        for (size_t i = 1; i < N + 1; i++)
            table[i] = 0;

        for (size_t i = 0; i < trust.size(); i++)
            table.at(trust.at(i).at(1))++;

        auto judge = --table.end();

        auto it = std::find_if(trust.begin(), trust.end(), [=](const std::vector<int> &p) {
            return p.at(0) == judge->first;
        });

        return (judge->second == N - 1 && it == trust.end()) ? judge->first : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // int N = 3;
    // std::vector<std::vector<int>> data = {{1, 3}, {2, 3}, {3, 1}};
    // int N = 2;
    // std::vector<std::vector<int>> data = {{1, 2}};
    int N = 4;
    std::vector<std::vector<int>> data = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    auto result = s.findJudge(N, data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
