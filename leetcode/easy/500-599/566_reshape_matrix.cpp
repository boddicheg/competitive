#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
{
    if (nums.size() * nums.at(0).size() != r * c) return nums;

    vector<vector<int>> result;
    int index_i = 0, index_j = 0;
    for (int i = 0; i < r; ++i)
    {
        vector<int> element;
        for (int j = 0; j < c; ++j)
        {
            element.push_back(nums.at(index_i).at(index_j));

            if (index_j < nums.at(0).size() - 1)
                index_j++;
            else
            {
                index_i++;
                index_j = 0;
            }
        }
        result.push_back(element);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> data =
    {
        {1, 2},
        {3, 4}
    };
    auto result = matrixReshape(data, 1, 4);
    for (const auto &row : result)
    {
        for (const auto &e : row)
            std::cout << e << " ";
        std::cout << std::endl;
    }
    return 0;
}