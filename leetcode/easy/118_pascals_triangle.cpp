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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        if (numRows >= 1)
            result.push_back({ 1 });
        if (numRows >= 2)
            result.push_back({ 1, 1 });

        for (int i = 2; i < numRows; ++i)
        {
            vector<int> line(i + 1, 1);
            for (int j = 1; j < i; ++j)
                line.at(j) = result.at(i - 1).at(j) + result.at(i - 1).at(j - 1);
            result.push_back(line);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.generate(5);
    for (const auto &v : result)
        print(v);
    return 0;
}
