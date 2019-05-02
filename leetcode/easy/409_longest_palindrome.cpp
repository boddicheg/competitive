#include <iostream>
#include <vector>
#include <unordered_map>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:

    int longestPalindrome(string s)
    {
        std::unordered_map<char, int> table;
        for(const auto& e: s)
            table[e]++;
        for(const auto& e: table)
            std::cout << e << std::endl;
        int odd = 0;
        int even = 0;

        for(const auto& e: table)
        {
            if(e.second % 2 == 0)
                even += e.second;
            else if((e.second - 1 != 0) && (e.second - 1) % 2 == 0)
            {
                even += e.second - 1;
                odd = 1;
            }
            else
                odd = 1;
        }

        return even + ((odd == 1) ? 1 : 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.longestPalindrome("ccc") << std::endl;
    std::cout << s.longestPalindrome("abccccdd") << std::endl;
    std::cout << s.longestPalindrome("abccvvccdjkxjcvdfdfmdfdnsccbd") << std::endl;
    return 0;
}
