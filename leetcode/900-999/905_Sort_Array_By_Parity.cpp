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
    std::vector<int> sortArrayByParity(const std::vector<int> &A)
    {
        std::vector<int> result(A.size(), 0);
        size_t lidx = 0;
        size_t ridx = A.size() - 1; 
        for (const auto &e : A)
        {
            if (e % 2 == 0)
                result.at(lidx++) = e;
            else
                result.at(ridx--) = e;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.sortArrayByParity({3, 1, 5, 2, 9,5, 2, 4});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
