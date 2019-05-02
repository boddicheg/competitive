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
    int maxProfit(vector<int> &prices)
    {
        int max_curr = 0;
        int max_so_far = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            max_curr += prices[i] - prices[i - 1];
            max_curr = std::max(0, max_curr);
            max_so_far = std::max(max_curr, max_so_far);
        }
        return max_so_far;
    }
};
int main(int argc, char const *argv[])
{
    std::vector<int> data1 = {7, 1, 5, 3, 6, 4};
    std::vector<int> data2 = {1, 2, 3, 4, 5};
    std::vector<int> data3 = {7, 6, 4, 3, 1};
    Solution s;
    std::cout << s.maxProfit(data1) << std::endl;
    std::cout << s.maxProfit(data2) << std::endl;
    std::cout << s.maxProfit(data3) << std::endl;
    return 0;
}
