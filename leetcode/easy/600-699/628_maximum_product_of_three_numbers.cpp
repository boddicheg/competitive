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
    int maximumProduct(vector<int> &nums)
    {
        int min1 = std::numeric_limits<int>::max(), min2 = std::numeric_limits<int>::max();
        int max1 = std::numeric_limits<int>::min(), max2 = std::numeric_limits<int>::min(), max3 = std::numeric_limits<int>::min();

        for (const auto &e : nums)
        {
            // min
            if (e <= min1)
            {
                min2 = min1;
                min1 = e;
            }
            else if (e <= min2)
                min2 = e;
            // max
            if(e >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = e;
            }
            else if(e >= max2)
            {
                max3 = max2;
                max2 = e;
            }
            else if(e >= max3)
            {
                max3 = e;
            }
        }

        return std::max(min1 * min2 * max1, max1 * max2 * max3);
    }
};

int main(int argc, char const *argv[])
{
    //[-4,-3,-2,-1,60] // 720
    // [-1,-2,1,2,3] // 6
    std::vector<int> data = {-1,-2,1,2,3};
    Solution s;
    std::cout << s.maximumProduct(data) << std::endl;
    return 0;
}
