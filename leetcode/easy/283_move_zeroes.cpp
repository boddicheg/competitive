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
    void moveZeroes(vector<int>& nums)
    {
        size_t size = nums.size();
        for(size_t i = 0; i < size; i++)
        {
            if(nums.at(i) == 0)
            {
                auto it = nums.begin() + i;
                std::rotate(it, it + 1, nums.end());
                i--;
                size--;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data = { 1, 0, 2, 0, 0, 1};
    Solution s;
    s.moveZeroes(data);
    return 0;
}
