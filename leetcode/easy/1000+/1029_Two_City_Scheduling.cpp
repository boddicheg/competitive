#include <iostream>
#include <vector>
#include <set>
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
    int twoCitySchedCost(std::vector<std::vector<int>> &costs)
    {
        int result = 0;
        std::vector<std::pair<int, int>> table;
        for (size_t i = 0; i < costs.size(); i++)
        {
            table.push_back({costs.at(i).at(0) - costs.at(i).at(1), i});
        }
        std::sort(table.begin(), table.end());
        
        for (size_t i = 0; i < costs.size() / 2; i++)
        {
            result += costs.at(table.at(i).second).at(0);
        }
        
        for (size_t i = costs.size() / 2; i < costs.size(); i++)
        {
            result += costs.at(table.at(i).second).at(1);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::vector<int>> data = {
        {10, 20}, {30, 200}, {400, 50}, {30, 40}
    };
    auto result = s.twoCitySchedCost(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
