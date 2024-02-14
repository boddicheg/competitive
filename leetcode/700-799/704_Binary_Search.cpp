#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

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
    int search(std::vector<int>& nums, int target) {
        size_t size = nums.size();
        int left_border = 0;
        int right_border = size - 1;

        while((right_border - left_border) > 1 )
        {
            int center = (right_border + left_border) / 2;
            // std::cout << "[" << left_border << "," << right_border << "]" << std::endl;

            if (nums.at(center) > target)
            {
                right_border = center;
            }
            else if (nums.at(center) < target)
            {
                left_border = center;
            }
            else 
                return center;
        }
        if (nums.at(left_border) == target) return left_border;
        if (nums.at(right_border) == target) return right_border;

        return -1;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v {-1,0,3,5,9,12};
    auto result = s.search(v, 2);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
