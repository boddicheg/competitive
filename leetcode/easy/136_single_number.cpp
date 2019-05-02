#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (const auto& n: nums)
            result ^= n;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    bitset<8> a(5);
    bitset<8> b(6);
    bitset<8> c(10);
    std::cout << a.to_string() << ", " << b.to_string() << std::endl
              << (a ^ b).to_string() << std::endl;
    return 0;
}
