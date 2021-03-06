#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
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
    vector<int> countBits(int num)
    {
        vector<int> result;
        for (int i = 0; i <= num; ++i)
        {
            std::bitset<32> n(i);
            result.push_back(n.count());
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    print(s.countBits(20));
    return 0;
}
