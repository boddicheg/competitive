#include <iostream>
#include <vector>
#include <map>
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
    int dominantIndex(vector<int> &nums)
    {
        if (nums.size() == 1) return 0;

        int first = std::numeric_limits<int>::min();
        int second = std::numeric_limits<int>::min();
        int idx = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) >= first)
            {
                second = first;
                first = nums.at(i);
                idx = i;
            }

            if(nums.at(i) < first && nums.at(i) > second)
                second = nums.at(i);
        }
        return (first >= second * 2) ? idx : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {3, 6, 1, 0};
    // std::vector<int> data = {1, 2, 3, 4, 7};
    // std::vector<int> data = {1, 2, 3, 4, 8};
    std::vector<int> data = {0,0,3,2};
    std::cout << s.dominantIndex(data) << std::endl;
    return 0;
}
