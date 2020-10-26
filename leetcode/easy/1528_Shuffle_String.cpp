#include <iostream>
#include <vector>
#include <utility>
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
    std::string restoreString(std::string s, const std::vector<int>& indices)
    {
        std::string result = s;
        for (size_t i = 0; i < s.size(); i++)
            result[indices.at(i)] = s.at(i);

        return result;     
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.restoreString("codeleet",{4,5,6,7,0,2,1,3});
    std::cout << "Result: " << result << std::endl;
    return 0;
}
