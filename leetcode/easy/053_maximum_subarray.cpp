#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max_curr = 0;
        int max_so_far = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i)
        {
            max_curr += nums[i];
            max_so_far = std::max(max_curr, max_so_far);
            max_curr = std::max(0, max_curr);
        }
        return max_so_far;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data1 = {-1};
    Solution s;
    std::cout << s.maxSubArray(data1) << std::endl;
    return 0;
}
