#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

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
    bool checkWithSkipped(string s, int skipped)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end)
        {
            if (end == skipped)
            {
                end -- ;
                continue;
            }

            if (start == skipped)
            {
                start ++ ;
                continue;
            }

            if (s.at(start ++ ) != s.at(end--))
                return false;
        }
        return true;
    }

    bool validPalindrome(string s) {
        if (s.size() == 1) return true;

        int start = 0;
        int end = s.size() - 1;
        bool can_skip = false;
        while (start <= end)
        {
            if (s.at(start) != s.at(end))
            {
                can_skip = true;
                break;
            }
            start ++;
            end --;
        }
        if (!can_skip) return true;

        return checkWithSkipped(s, start) || checkWithSkipped(s, end);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {};
    auto result = s.validPalindrome("abc");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
