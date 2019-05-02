#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        std::string str_repr = bitset<32>(n).to_string();
        bitset<32> rev(std::string(str_repr.rbegin(), str_repr.rend()));
        return rev.to_ulong();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseBits(43261596) << std::endl;
    return 0;
}