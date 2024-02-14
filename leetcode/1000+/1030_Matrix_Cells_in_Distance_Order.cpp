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

std::ostream &operator<<(std::ostream &ss, const std::vector<int> &c)
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
    inline int dist(int r1, int c1, int r2, int c2)
    {
        return std::abs(r1 - r2) + std::abs(c1 - c2);
    }

    struct Cell
    {
        int x;
        int y;
        int dist;
    };

    std::vector<std::vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
    {
        std::vector<std::vector<int>> result;
        std::vector<Cell> data;
        for (size_t i = 0; i < R; i++)
        {
            for (size_t j = 0; j < C; j++)
            {
                int distance = dist(r0, c0, i, j);
                data.push_back({i, j, distance});
            }
        }

        std::sort(data.begin(), data.end(), [](const Cell& a, const Cell& b) {
            return a.dist < b.dist;
        });

        for (auto &&i : data) result.push_back({i.x, i.y});
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.allCellsDistOrder(1, 2, 0, 0);
    // auto result = s.allCellsDistOrder(2, 2, 0, 1);
    auto result = s.allCellsDistOrder(2, 3, 1, 2);
    // std::cout << "Reslt: " << result << std::endl;
    return 0;
}
