#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T& container)
{
    std::cout << "[";
    for(const auto& e: container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        int x = m;
        int y = n;
        for(const auto p: ops)
        {
            x = std::min(x, p.at(0));
            y = std::min(y, p.at(1));
        }
        return x * y;
    }
};

int main(int argc, char const *argv[])
{

    Solution s;
    return 0;
}
