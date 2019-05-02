#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 0 || nums.size() == 2)
            return -1;
        if (nums.size() == 1)
            return 0;

        int sum = 0;
        for (const auto &e : nums)
            sum += e;

        int left = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (left == sum - left - nums.at(i))
                return i;
            left += nums.at(i);
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = { 1, 2, 3};
    // std::vector<int> data = {1, 7, 3, 6, 5, 6};
    std::vector<int> data = { -1, -1, -1, -1, -1, -1};

    std::cout << s.pivotIndex(data) << std::endl;
    return 0;
}
