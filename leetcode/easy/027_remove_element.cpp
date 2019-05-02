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
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data = {1, 2, 1, 1, 3};
    Solution s;
    s.removeElement(data, 1);
    return 0;
}
