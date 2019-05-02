#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 1; i > 0; i *= 3)
    {
        std::cout << i << " " << std::boolalpha << s.isPowerOfThree(i) << std::endl;
    }
    return 0;
}