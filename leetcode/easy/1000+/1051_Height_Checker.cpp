#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

std::ostream &operator<<(std::ostream &ss, const std::vector<int> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    int heightChecker(const std::vector<int> &heights)
    {
        std::vector<int> heights2 = heights;
        std::sort(heights2.begin(), heights2.end());

        int result = 0;
        for (size_t i = 0; i < heights.size(); i++)
        {
            if (heights.at(i) != heights2.at(i))
                result++;
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.heightChecker({1, 1, 4, 2, 1, 3});
    auto result = s.heightChecker({1,2,1,2,1,1,1,2,1});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
