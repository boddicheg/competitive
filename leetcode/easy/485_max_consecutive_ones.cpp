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
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int result = 0;
        int tmp = 0;
        for(const auto& digit: nums)
        {
            if(digit == 1)
                tmp++;
            else
            {
                result = std::max(result, tmp);
                tmp = 0;
            }
        }
        return std::max(result, tmp);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
