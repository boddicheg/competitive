#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

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
    int minMoves(vector<int> &nums)
    {
        return std::accumulate(nums.begin(), nums.end(), 0) - (*(std::min_element(nums.begin(), nums.end()))) * nums.size();
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data = { 1, 2147483647};
    Solution s;
    std::cout << "Moves: " << s.minMoves(data) << std::endl;
    return 0;
}
