#include <iostream>
#include <vector>
#include <map>
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

struct cmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        std::map<int, int, cmp> table;
        vector<string> result(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            table[nums.at(i)] = i;

        int medals = 1;
        for (const auto &e : table)
        {
            if (medals == 1)
                result.at(e.second) = "Gold Medal";
            else if (medals == 2)
                result.at(e.second) = "Silver Medal";
            else if (medals == 3)
                result.at(e.second) = "Bronze Medal";
            else
                result.at(e.second) = std::to_string(medals);
            medals++;
        }

        print(table);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<int> v = { 5, 4, 3, 2, 1 };
    std::vector<int> v = { 10, 5, 9, 3, 8, 1 };
    Solution s;
    auto result = s.findRelativeRanks(v);
    print(result);
    return 0;
}
