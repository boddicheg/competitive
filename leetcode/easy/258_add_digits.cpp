#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int addDigits(int num)
    {
        return num - 9 * std::floor((num - 1) / 9);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        int result = s.addDigits(38);
        watch(result);
    }
    return 0;
}
