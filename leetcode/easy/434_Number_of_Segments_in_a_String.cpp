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
    int countSegments(std::string s) {
        if (s.empty())
            return 0;

        s += " ";
        int count = 0;
        bool c = false;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (s.at(i) == ' ')
            {
                if (c)
                    count ++;

                c = false;
            }
            else
                c = true;
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.countSegments("love live! mu'sic forever");
    std::cout << "Result: " << result << std::endl;
    result = s.countSegments("Hello, my name is John");
    std::cout << "Result: " << result << std::endl;
    result = s.countSegments("Hello");
    std::cout << "Result: " << result << std::endl;
    result = s.countSegments("");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
