#include <iostream>
#include <vector>
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
    int minCostClimbingStairs(vector<int> &cost)
    {
        int f1 = cost.at(0), f2 = cost.at(1);
        for (int i = 2; i < cost.size(); ++i)
        {
            int f0 = cost.at(i) + std::min(f1, f2);
            f1 = f2;
            f2 = f0;
        }
        return std::min(f2, f1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> cost = {
        1, 100, 1, 1, 1, 100, 1, 1, 100, 1
        // 10, 15, 20
        // 10, 15, 20, 30
    };
    std::cout << s.minCostClimbingStairs(cost) << std::endl;
    return 0;
}
