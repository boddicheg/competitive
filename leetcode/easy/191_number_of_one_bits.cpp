#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return bitset<32>(n).count();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 130; ++i)
    {
        std::cout << i << " " << s.hammingWeight(i) << std::endl;
    }
    return 0;
}