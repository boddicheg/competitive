#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &A)
    {
        vector<vector<int>> result(A.at(0).size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A.at(i).size(); ++j)
                result.at(j).at(i) = A.at(i).at(j);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<int>> data1 =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    std::vector<std::vector<int>> data2 =
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    Solution s;
    auto result1 = s.transpose(data1);
    for (const auto &e : result1)
        print(e);
    auto result2 = s.transpose(data2);
    for (const auto &e : result2)
        print(e);
    return 0;
}
