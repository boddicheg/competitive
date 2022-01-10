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
    std::string defangIPaddr(std::string address)
    {
        size_t idx = 0;

        while(idx < address.size())
        {
            std::cout << "-> " << address.at(idx) << std::endl;
            if (address.at(idx) == '.')
            {
                address.insert(idx, "[");
                idx ++;
                address.insert(idx + 1, "]");
            }
            idx ++;
        }
        return address;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.defangIPaddr("192.168.1.1");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
