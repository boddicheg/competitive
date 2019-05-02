#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
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

struct IntDefaultedToPlusInf
{
    int i = std::numeric_limits<int>::max();
};

struct IntDefaultedToMinusInf
{
    int i = std::numeric_limits<int>::min();
};

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        std::map<int, int> table;
        std::map<int, IntDefaultedToPlusInf> left_idx;
        std::map<int, IntDefaultedToMinusInf> right_idx;

        if(nums.size() == 1) return 1;

        int max_freq = std::numeric_limits<int>::min();

        for (int i = 0; i < nums.size(); i++)
        {
            int e = nums.at(i);
            table[e]++;
            left_idx[e].i = std::min(i, left_idx[e].i);
            right_idx[e].i = std::max(i, right_idx[e].i);
            max_freq = std::max(table[e], max_freq);
        }

        int min_diff = std::numeric_limits<int>::max();

        for(const auto& e: table)
        {
            //std::cout << e.first << " - dist[" << right_idx[e.second].i - left_idx[e.second].i << "] - freq = " << e.second << std::endl;
            if(e.second != max_freq)
                continue;
            min_diff = std::min(min_diff, right_idx[e.first].i - left_idx[e.first].i);
        }
        return min_diff + 1;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data =
    {
        1, 2, 2, 3, 1, 4, 2
        // 1, 2, 2, 3, 1
        // 1
        // 1, 1
    };
    Solution s;
    std::cout << s.findShortestSubArray(data) << std::endl;
    return 0;
}
