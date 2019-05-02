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
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data = {1, 1, 1, 2, 3};
    Solution s;
    s.removeDuplicates(data);
    return 0;
}
