#include <iostream>
#include <vector>
using namespace std;

int neighbours(const vector<vector<int>>& grid, int i, int j)
{
    int count = 0;
    if(i - 1 < 0 || grid[i - 1][j] == 0) count ++;
    if(i + 1 >= grid.size() || grid[i + 1][j] == 0) count ++;

    if(j - 1 < 0 || grid[i][j - 1] == 0) count ++;
    if(j + 1 >= grid.at(0).size() || grid[i][j + 1] == 0) count ++;

    return count;
}

int islandPerimeter(vector<vector<int>>& grid)
{
    int result = 0;
    for(size_t i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid.at(i).size(); ++j)
        {
            if (grid.at(i).at(j) == 0) continue;
            result += neighbours(grid, i, j);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> data = {
        { 0,1,0,0,0 },
        { 1,1,1,1,1 },
        { 0,1,0,0,0 },
        { 1,1,0,0,0 }
    };
    int result = islandPerimeter(data);
    std::cout << result << std::endl;
    return 0;
}