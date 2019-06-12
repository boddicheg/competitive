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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
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
    int largestPerimeter(std::vector<int> &A)
    {
        std::sort(A.begin(), A.end());
        for (int i = A.size() - 3; i >= 0; i--)
        {
            if (A.at(i) + A.at(i + 1) > A.at(i + 2))
            {
                return A.at(i) + A.at(i + 1) + A.at(i + 2);
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data = {
        // 2,1,2
        1,2,1
        // 3,2,3,4
        // 3,6,2,3
    };
    Solution s;
    auto result = s.largestPerimeter(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
