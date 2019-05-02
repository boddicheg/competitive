/**
    https://leetcode.com/problems/valid-parentheses/
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.

    Note that an empty string is also considered valid.

    Example 1:

    Input: "()"
    Output: true

    Example 2:

    Input: "()[]{}"
    Output: true

    Example 3:

    Input: "(]"
    Output: false

    Example 4:

    Input: "([)]"
    Output: false

    Example 5:

    Input: "{[]}"
    Output: true

    Results:
    Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
    Memory Usage: 8.7 MB, less than 99.00% of C++ online submissions for Valid Parentheses.
 */

#include <iostream>
#include <vector>
#include <stack>
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

class Solution
{
public:
    bool isValid(string s)
    {
        std::stack<char> st;
        for (const auto &e : s)
        {
            switch (e)
            {
            case '(':
            {
                st.push('(');
                break;
            }
            case ')':
            {
                if (st.empty())
                    return false;
                char t = st.top();
                if (t != '(')
                    return false;
                st.pop();
                break;
            }
            case '[':
            {
                st.push('[');
                break;
            }
            case ']':
            {
                if (st.empty())
                    return false;
                char tt = st.top();
                if (tt != '[')
                    return false;
                st.pop();
                break;
            }
            case '{':
            {
                st.push('{');
                break;
            }
            case '}':
            {
                if (st.empty())
                    return false;
                char ttt = st.top();
                if (ttt != '{')
                    return false;
                st.pop();
                break;
            }
            }
        }
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.isValid("()") << std::endl;
    std::cout << std::boolalpha << s.isValid("()[]{}") << std::endl;
    std::cout << std::boolalpha << s.isValid("(]") << std::endl;
    std::cout << std::boolalpha << s.isValid("([)]") << std::endl;
    std::cout << std::boolalpha << s.isValid("{[]}") << std::endl;
    return 0;
}
