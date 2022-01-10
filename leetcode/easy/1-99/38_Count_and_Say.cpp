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
    std::string countAndSay(int n)
    {
        std::string start = "1";
        std::string current = "";
        int count = 0;
        char digit;

        for (size_t idx = 2; idx <= n; idx++)
        {
            for (auto &&i : start)
            {
                if (count == 0)
                {
                    count = 1;
                    digit = i;
                }
                else
                {
                    if (i == digit)
                        count ++;
                    else
                    {
                        current += std::to_string(count) + digit;
                        digit = i;
                        count = 1;
                    }

                }


            }
            current += std::to_string(count) + digit;
            start = current;
            current = "";
            count = 0;
        }

        return start;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.countAndSay(4);
    std::cout << "Result: " << result << std::endl;
    auto result1 = s.countAndSay(1);
    std::cout << "Result: " << result1 << std::endl;
    return 0;
}
