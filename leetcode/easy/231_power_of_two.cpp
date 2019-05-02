#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && bitset<32>(n).count() == 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.isPowerOfTwo(-2147483648) << std::endl;
    return 0;
}