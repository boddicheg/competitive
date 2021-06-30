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
    std::vector<int> replaceElements(std::vector<int>& arr)
    {
        int length = arr.size();

        if (length > 1)
        {
            int max = arr.at(length - 1);
            for (int i = length - 2; i >= 0; i--)
            {
                int tmp = arr.at(i);
                arr.at(i) = max;
                max = std::max(tmp, max);
            }
        }

        arr.at(arr.size() - 1 ) = -1;
        return arr;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v {17,18,5,4,6,1};
    // std::vector<int> v {400};
    auto result = s.replaceElements(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
