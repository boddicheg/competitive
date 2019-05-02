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
    vector<int> getRow(int rowIndex)
    {
        vector<int> prev;
        if (rowIndex >= 0) prev = { 1 };
        if (rowIndex >= 1) prev = { 1, 1 };

        for (int i = 2; i <= rowIndex; ++i)
        {
            vector<int> line(i + 1, 1);
            for (int j = 1; j < i; ++j)
                line.at(j) = prev.at(j) + prev.at(j - 1);
            prev = line;
        }
        return prev;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.getRow(5);
    print(result);
    return 0;
}
