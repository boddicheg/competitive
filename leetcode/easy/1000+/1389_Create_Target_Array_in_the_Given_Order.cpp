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
    std::vector<int> createTargetArray(const std::vector<int>& nums, const std::vector<int>& index)
    {
        std::vector<int> result;

        for (size_t i = 0; i < nums.size(); i++)
        {
            int num = nums.at(i);
            int idx = index.at(i);
            result.insert(result.begin() + idx, num);
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.createTargetArray({0,1,2,3,4}, {0,1,2,2,1});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
