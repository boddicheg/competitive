#include <iostream>
#include <vector>
#include <set>
#include <cmath>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        vector<vector<int>> result(M);
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M.at(i).size(); j++)
            {
                int surrounding = 0;
                int sum = 0;

                if (i - 1 >= 0)
                {
                    surrounding++;
                    sum += M.at(i - 1).at(j);
                }

                if (i - 1 >= 0 && j + 1 < M.at(i).size())
                {
                    surrounding++;
                    sum += M.at(i - 1).at(j + 1);
                }

                if (i - 1 >= 0 && j - 1 >= 0)
                {
                    surrounding++;
                    sum += M.at(i - 1).at(j - 1);
                }

                if (i + 1 < M.size())
                {
                    surrounding++;
                    sum += M.at(i + 1).at(j);
                }

                if (i + 1 < M.size() && j + 1 < M.at(i).size())
                {
                    surrounding++;
                    sum += M.at(i + 1).at(j + 1);
                }

                if (i + 1 < M.size() && j - 1 >= 0)
                {
                    surrounding++;
                    sum += M.at(i + 1).at(j - 1);
                }

                if (j - 1 >= 0)
                {
                    surrounding++;
                    sum += M.at(i).at(j - 1);
                }

                if (j + 1 < M.at(i).size())
                {
                    surrounding++;
                    sum += M.at(i).at(j + 1);
                }

                surrounding++;
                sum += M.at(i).at(j);

                result.at(i).at(j) = std::floor(sum / surrounding);
                // std::cout << sum << "/" <<  surrounding << " = " << std::floor(ones / surrounding) << std::endl;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> M =
    {
        // {1, 1, 1},
        // {1, 0, 1},
        // {1, 1, 1},
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10},
        {11, 12, 13},
        {14, 15, 16},
    };
    Solution s;
    auto result = s.imageSmoother(M);
    for (const auto &e : result)
        print(e);
    return 0;
}
