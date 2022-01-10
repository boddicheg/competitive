#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:

    double calculateArea(const vector<int> &a1, const vector<int> &a2, const vector<int> &a3)
    {
        return std::abs(0.5 * ((a1[0] - a3[0]) * (a2[1] - a3[1]) - (a2[0] - a3[0]) * (a1[1] - a3[1])));
    }

    double largestTriangleArea(const vector<vector<int>> &points)
    {
        double result = 0.0;
        for(const auto& a1: points)
            for(const auto& a2: points)
                for(const auto& a3: points)
                {
                    result = std::max(calculateArea(a1, a2, a3), result);
                }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.largestTriangleArea({ {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0} }) << std::endl;
    return 0;
}
