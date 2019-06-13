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
    int surfaceArea(std::vector<std::vector<int>> &grid)
    {
        int N = grid.size();
        int result = 0;
        int intersections = 0;
        std::vector<int> dirx = {0, 1, 0, -1};
        std::vector<int> diry = {-1, 0, 1, 0};

        for (size_t i = 0; i < N; i++)
        {
            for (size_t j = 0; j < N; j++)
            {
                int z = grid.at(j).at(i);
                if (z == 0)
                    continue;
                // Calculate all sides
                result += ((z > 0) ? 2 : 0) + 4 * z;
                // Calculate intersections
                for (size_t k = 0; k < 4; k++)
                {
                    int blocked = 0;
                    int xidx = i + dirx[k];
                    int yidx = j + diry[k];

                    if (xidx >= 0 && xidx < N && yidx >= 0 && yidx < N)
                    {
                        int bricks = grid.at(yidx).at(xidx);
                        blocked = std::min(z, bricks);
                    }
                    intersections += blocked;
                }
            }
        }
        return result - intersections;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::vector<int>> grid =
        {
            // {1, 2}, {3, 4}
            {3, 3, 3},
            {3, 4, 5},
            {5, 0, 4}};
    auto result = s.surfaceArea(grid);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
