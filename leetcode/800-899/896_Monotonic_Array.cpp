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
    bool isMonotonic(std::vector<int> &A)
    {
        int increases = 0;
        int decreases = 0;
        
        for(int i = 0; i < A.size() - 1; i++)
        {
            if (A.at(i) > A.at(i + 1))
                decreases++;
            else if (A.at(i) < A.at(i + 1))
                increases++;
        }
        std::cout << increases << " " << decreases << std::endl;
        return (decreases != 0 && increases == 0) ||
               (decreases == 0 && increases != 0) ||
               (decreases == 0 && increases == 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> data = {
        // 1,2,2,3
        // 6,5,4,4
        // 1,3,2
        // 1,2,4,5
        // 1,1,1
        1
    };
    auto result = s.isMonotonic(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
