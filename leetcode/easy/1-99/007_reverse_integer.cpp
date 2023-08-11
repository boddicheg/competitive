/**
    https://leetcode.com/problems/reverse-integer/
    Given a 32-bit signed integer, reverse digits of an integer.

    Example 1:
    Input: 123
    Output: 321

    Example 2:
    Input: -123
    Output: -321

    Example 3:
    Input: 120
    Output: 21

    Note:
    Assume we are dealing with an environment which could only store integers within
    the 32-bit signed integer range: [−2^31,  2^31 − 1].
    For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

    Results:
    Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
    Memory Usage: 8.5 MB, less than 96.26% of C++ online submissions for Reverse Integer.
 */

#include <iostream>
#include <vector>
#include <algorithm>

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

constexpr int imin = std::numeric_limits<int>::min() / 10;
constexpr int imax = std::numeric_limits<int>::max() / 10;

class Solution
{
public:
    int reverse(int x)
    {
        int result = 0;
        int multipier = 10;
        bool is_sign = x <= 0;
        if (x == std::numeric_limits<int>::min()) return 0;
        x = std::abs(x);

        while (true)
        {
            if (x == 0)
                break;

            if (result > imax)
                return 0;

            if (result < imin)
                return 0;

            result = x % 10 + result * multipier;
            x /= 10;

            if (multipier != 10)
                multipier = 10;
        }

        return result * ((is_sign) ? -1 : 1);
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverse(123) << std::endl;
    std::cout << s.reverse(-2147483648) << std::endl;
    return 0;
}
