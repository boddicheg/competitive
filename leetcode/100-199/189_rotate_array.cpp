#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T& container)
{
    std::cout << "[";
    for(const auto& e: container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        std::rotate(nums.rbegin(), nums.rbegin() + k % nums.size(), nums.rend());
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data = {1,2,3,4,5,6,7};
    Solution s;
    s.rotate(data, 3);
    print(data);

    return 0;
}
