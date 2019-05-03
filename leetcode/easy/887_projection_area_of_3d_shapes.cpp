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
    int projectionArea(vector<vector<int>> &grid)
    {
        int result = 0;
        int n = grid.size();
        // yx
        for (int i = 0; i < n; ++i)
        {
            int max_e = -1;
            for (int j = 0; j < n; ++j)
            {
                if (grid.at(i).at(j) != 0)
                    result++;
                max_e = std::max(grid.at(i).at(j), max_e);
            }
            result += max_e;
            max_e = -1;
            for (int j = n - 1; j >= 0; --j)
            {
                max_e = std::max(grid.at(j).at(i), max_e);
            }
            result += max_e;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> grid =
    {
        {1, 2},
        {3, 4}
    };
    std::cout << s.projectionArea(grid) << std::endl;
    return 0;
}
