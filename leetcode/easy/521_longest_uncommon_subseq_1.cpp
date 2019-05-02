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
    int findLUSlength(string a, string b)
    {
        if(a == b) return -1;
        return std::max(a.size(), b.size());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.findLUSlength("qwexcdss", "qweqw") << std::endl;
    return 0;
}
