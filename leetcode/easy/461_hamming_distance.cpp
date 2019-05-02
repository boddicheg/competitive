#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int z = x ^ y;
        std::bitset<64> sett(z);
        return sett.count();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.hammingDistance(10, 20);
    return 0;
}
