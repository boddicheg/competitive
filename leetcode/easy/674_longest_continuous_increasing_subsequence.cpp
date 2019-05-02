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
    int findLengthOfLCIS(vector<int> &nums)
    {
        int count = 0;
        int longest = 0;
        int previous = std::numeric_limits<int>::min();
        for (const auto &e : nums)
        {
            if (e > previous)
            {
                count++;
                longest = std::max(longest, count);
            }
            else
            {
                longest = std::max(longest, count);
                count = 1;
            }
            std::cout << "Longest: " << longest << ", count is " << count << std::endl;
            previous = e;
        }
        return longest;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> seq = {2,2,2,2,1, 3,4,5};
    std::vector<int> seq = {1, 3, 5, 6, 4, 7};
    std::cout << s.findLengthOfLCIS(seq) << std::endl;
    return 0;
}
