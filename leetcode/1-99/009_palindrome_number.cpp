/**
    https://leetcode.com/problems/palindrome-number/

    Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

    Example 1:

    Input: 121
    Output: true

    Example 2:

    Input: -121
    Output: false
    Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

    Example 3:

    Input: 10
    Output: false
    Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

    Follow up:

    Coud you solve it without converting the integer to a string?
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

/**
 * Runtime: 16 ms, faster than 100.00% of C++ online submissions for Palindrome Number.
 * Memory Usage: 8.5 MB, less than 98.34% of C++ online submissions for Palindrome Number.
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0) return false;
        int left = 0, right = 0;

        int digits = (int)log10(x) + 1;
        int mult = pow(10, digits - 1);

        while (x != 0)
        {
            right = x % 10;
            x /= 10;
            mult /= 10;
            digits--;

            if (mult == 0 && right != 0)
                return true;

            left = x / mult;
            x %= mult;
            mult /= 10;

            if (left != right)
                return false;
        }

        return true;
    }
};

/**
 * Runtime: 20 ms, faster than 99.57% of C++ online submissions for Palindrome Number.
 * Memory Usage: 8.6 MB, less than 98.34% of C++ online submissions for Palindrome Number.
 */

class Solution1
{
    bool isPalindrome(int x)
    {
        auto s = std::to_string(x);
        return s == std::string(s.rbegin(), s.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.isPalindrome(121) << std::endl;
    return 0;
}
