#include <iostream>
#include <vector>
#include <map>
#include <stack>
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
    int evalRPN(vector<string> &tokens)
    {
        std::stack<int> result;
        bool prev_digit = false;
        std::string number;
        for (const auto &e : tokens)
        {
            if (e == "+" || e == "-" || e == "*" || e == "/")
            {
                int right = result.top();
                result.pop();
                int left = result.top();
                result.pop();

                int tmp = 0;

                if (e == "+")
                    tmp = left + right;
                else if (e == "-")
                    tmp = left - right;
                else if (e == "*")
                    tmp = left * right;
                else if (e == "/")
                    tmp = left / right;
                // std::cout << left << " " << e << " " << right << " = " << tmp << std::endl;
                result.push(tmp);
            }
            else
                result.push(std::stoi(e));
        }

        if (result.empty())
            return std::stoi(number);

        return result.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<string> tokens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
    vector<string> tokens = { "4", "13", "5", "/", "+" };
    std::cout << s.evalRPN(tokens) << std::endl;
    return 0;
}
