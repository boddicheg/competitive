#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        int64_t first = std::numeric_limits<int64_t>::min();
        int64_t second = std::numeric_limits<int64_t>::min();
        int64_t third = std::numeric_limits<int64_t>::min();

        if (nums.size() == 1)
            return nums.at(0);
        
        if (nums.size() == 2)
            return std::max(nums.at(0), nums.at(1));

        for (size_t i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) > first)
            {
                third = second;
                second = first;
                first = nums.at(i);
            }
            else if (nums.at(i) < first && nums.at(i) > second)
            {
                third = second;
                second = nums.at(i);
            }
            else if (nums.at(i) < second && nums.at(i) > third)
            {
                third = nums.at(i);
            }
        }

        if (third != std::numeric_limits<int64_t>::min())
            return third;
        else return std::max(first, second);
        
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> v {3,2,1};
    // std::vector<int> v {1,2};
    // std::vector<int> v {2,2,3,1};
    std::vector<int> v {1,2,-2147483648};
    // std::vector<int> v {1,1,2};
    auto result = s.thirdMax(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
