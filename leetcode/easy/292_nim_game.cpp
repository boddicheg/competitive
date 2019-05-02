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
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 1; i < 10; ++i)
    {
        std::cout << i << ": Can win: " << std::boolalpha << s.canWinNim(i) << std::endl;
    }
    return 0;
}
