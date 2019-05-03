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
    int island(vector<vector<char>>& grid, int x, int y)
    {
        int result = 0;
        // std::cout << x << " " << y << " " << grid.size() << std::endl;

        if(x < 0 || x >= grid.size() || y < 0 || y >= grid.at(0).size())
            return result;

        if(grid.at(x).at(y) == '0' || grid.at(x).at(y) == '2')
            return result;
        else
        {
            result++;
            grid.at(x).at(y) = '2';
            // Check all directions
            result += island(grid, x + 1, y);
            result += island(grid, x - 1, y);
            result += island(grid, x, y + 1);
            result += island(grid, x, y - 1);
        }

        return result;
    }

    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        for(size_t x = 0; x < grid.size(); x++)
            for(size_t y = 0; y < grid.at(x).size(); y++)
            {
                int element = grid.at(x).at(y);
                if(element == '0' || element == '2') continue;

                int area = std::max(island(grid, x, y), result);
                if (area > 0) result ++;
            }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid = {
        {'0', '0', '0', '0', '0'},
        {'0', '1', '0', '0', '1'},
        {'0', '0', '0', '0', '1'},
        {'0', '0', '0', '0', '0'},
        {'0', '1', '1', '0', '0'}
    };

    Solution s;
    std::cout << s.numIslands(grid) << std::endl;
    return 0;
}
