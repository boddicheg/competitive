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

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        std::map<int, int> table;
        for (const auto &e : nums)
            table[e]++;
        int max = 0;
        std::pair<int, int> prev;
        bool skip = true;
        for (const auto &e : table)
        {
            if (skip)
            {
                skip = false;
                prev = e;
                continue;
            }
            if (e.first - prev.first == 1 && e.second + prev.second > max)
                max = e.second + prev.second;
            prev = e;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {1, 3, 2, 2, 5, 2, 3, 7};
    std::vector<int> data = {1, 1, 1, 1};
    std::cout << s.findLHS(data) << std::endl;
    return 0;
}
