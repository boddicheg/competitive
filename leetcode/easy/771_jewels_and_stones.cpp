#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int count = 0;
        for(const auto& stone: S)
        {
            if(J.find(stone) != std::string::npos)
            {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.numJewelsInStones("aA", "aAAbbbb") << std::endl;
    return 0;
}
