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
    bool isPalindrome(std::string s)
    {
        int i = 0;
        int j = s.size() - 1;
        if (s.size() == 0)
            return true;

        bool result = true;

        while(i < j && i < s.size() && j >= 0)
        {
            char c1 = std::tolower(s.at(i));
            if (!isalnum(c1))
            {
                i++;
                continue;
            }

            char c2 = std::tolower(s.at(j));
            if (!isalnum(c2))
            {
                j--;
                continue;
            }

            if (c1 != c2)
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.isPalindrome("A man, a plan, a canal: Panama");
    std::cout << "Result: " << result << std::endl;
    result = s.isPalindrome("race a car");
    std::cout << "Result: " << result << std::endl;
    result = s.isPalindrome(".,");
    std::cout << "Result: " << result << std::endl;
    result = s.isPalindrome("0P");
    std::cout << "Result: " << result << std::endl;
    result = s.isPalindrome("a.");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
