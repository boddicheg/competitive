#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

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
    std::vector<std::string> findOcurrences(std::string text, std::string first, std::string second)
    {
        std::vector<std::string> result;

        bool find_first = false;
        bool find_second = false;

        std::string buffer;
        std::stringstream ss(text);

        while (std::getline(ss, buffer, ' '))
        {
            if (buffer == first && !find_first)
            {
                find_first = true;
                continue;
            }

            if (buffer == second && find_first && !find_second)
            {
                find_second = true;
                continue;
            }
            else if (buffer != second && buffer != first && find_first && !find_second)
                find_first = false;

            if (find_first && find_second)
            {
                result.push_back(buffer);
                find_first = find_second = false;

                if (buffer == first)
                    find_first = true;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::string text = "alice is a good girl she is a good student", first = "a", second = "good";
    std::string text = "we will we will rock you", first = "we", second = "will";
    // std::string text = "ypkk lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk ypkk ypkk ypkk lnlqhmaohv "
    //                    "lnlqhmaohv lnlqhmaohv lnlqhmaohv ypkk ypkk ypkk lnlqhmaohv lnlqhmaohv ypkk", first = "lnlqhmaohv", second = "ypkk";
    auto result = s.findOcurrences(text, first, second);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
