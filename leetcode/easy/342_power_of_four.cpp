#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isPowerOfFour(int n) {
        bitset<32> mask("01010101010101010101010101010101");
        bitset<32> bs(n);
        return n > 0 && bitset<32>(n).count() == 1 && (bs & mask) == bs;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 1; i < 10; i++)
    {
        std::cout << i << " " << std::boolalpha << s.isPowerOfFour(i) << std::endl;
    }
    return 0;
}