#include <iostream>
#include <vector>

using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        bool result = true;
        if (matrix.size() == 1) return true;

        size_t diagonals = matrix.size() + matrix.at(0).size() - 1;

        // Get first diagonal coords
        size_t index_i = matrix.size() - 1;
        size_t index_j = 0;

        for (size_t i = 0; i < diagonals; ++i)
        {
            int element = matrix.at(index_i).at(index_j);
            size_t di_idx = index_i;
            size_t dj_idx = index_j;
            while (di_idx < matrix.size() && dj_idx < matrix.at(0).size())
            {
                int current = matrix.at(di_idx).at(dj_idx);
                if (element != current)
                    return false;
                di_idx++;
                dj_idx++;
            }

            if (index_i > 0) index_i--;
            else
                index_j++;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix =
    {
        {1, 2, 3, 4},
        {5, 1, 1, 3},
        {9, 5, 1, 2}
    };
    Solution s;
    std::cout << std::boolalpha << s.isToeplitzMatrix(matrix) << std::endl;
    return 0;
}