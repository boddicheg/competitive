#include <iostream>
#include <vector>
#include <set>
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
    string removeOuterParentheses(string S)
    {
        std::string result;

        int it = 0;
        std::string buffer;

        for (const auto& e: S)
        {
            if (e == '(')
                ++it;
            if (e == ')')
                --it;
            buffer += e;

            if (it == 0)
            {
                result += {buffer.begin() + 1, buffer.end() - 1};
                buffer = {};
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.removeOuterParentheses("(()())(())");
    // auto result = s.removeOuterParentheses("(()())(())(()(()))");
    auto result = s.removeOuterParentheses("()()");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
