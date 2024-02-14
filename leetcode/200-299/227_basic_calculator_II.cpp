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
    std::string notation(const std::string &s)
    {
        std::stack<char> oper;
        std::map<char, int> priority =
        {
            { '(', 0 },
            { ')', 0 },
            { '+', 1 },
            { '-', 1 },
            { '*', 2 },
            { '/', 2 },
        };
        std::string expr;
        bool prev_digit = false;
        for (const auto &e : s)
        {
            if (e == ' ')
                continue;

            if (isdigit(e))
            {
                expr += e;
                prev_digit = true;
            }
            else
            {
                if (prev_digit)
                {
                    expr += ' ';
                    prev_digit = false;
                }

                if (e == '(')
                    oper.push(e);
                else if (e == ')')
                {
                    char tmp = -1;
                    while (tmp != '(')
                    {
                        if (oper.empty())
                            return 0;
                        tmp = oper.top();
                        oper.pop();
                        if (tmp != '(')
                            expr += tmp;
                    }
                }
                else if (e == '+' || e == '-' || e == '*' || e == '/')
                {
                    while(true)
                    {
                        if(oper.empty()) break;
                        char tmp = oper.top();
                        if (priority[tmp] >= priority[e])
                        {
                            oper.pop();
                            expr += tmp;
                            expr += ' ';
                        }
                        else
                            break;
                    }
                    oper.push(e);
                }
            }
        }

        while (!oper.empty())
        {
            expr += ' ';
            expr += oper.top();
            oper.pop();
        }
        return expr;
    }

    int unwind_notation(const std::string &expr)
    {
        std::stack<int> result;
        bool prev_digit = false;
        std::string number;
        for (const auto &e : expr)
        {
            // Number construction from string
            if (isdigit(e))
            {
                number += e;
                prev_digit = true;
                continue;
            }

            if (e == ' ' && prev_digit && !number.empty())
            {
                // std::cout << "constructed: " <<  number << std::endl;
                result.push(std::stoi(number));
                number = "";
                prev_digit = false;
                continue;
            }
            else if (e == ' ')
                continue;

            // Calucation

            int right = result.top();
            result.pop();
            int left = result.top();
            result.pop();

            std::cout << left << " " << e << " " << right << std::endl;

            int tmp = 0;

            if (e == '+')
                tmp = left + right;
            else if (e == '-')
                tmp = left - right;
            else if (e == '*')
                tmp = left * right;
            else if (e == '/')
                tmp = left / right;
            // std::cout << tmp << std::endl;
            result.push(tmp);
        }

        if(result.empty())
            return std::stoi(number);

        return result.top();
    }

    int calculate(string s)
    {
        std::cout << "Incoming string: " << s << std::endl;
        std::string expr = notation(s);
        std::cout << "Updated string: " << expr << std::endl;
        return unwind_notation(expr);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.calculate("1 + 1") << " = 2" << std::endl;
    std::cout << s.calculate("0+ 0") << " = 0" << std::endl;
    std::cout << s.calculate(" 2-1 + 2 ") << " = 3" << std::endl;
    std::cout << s.calculate("3+2*2") << " = 7" << std::endl;
    std::cout << s.calculate(" 3/2 ") << " = 1" << std::endl;
    std::cout << s.calculate(" 3+5 / 2 ") << " = 5" << std::endl;
    std::cout << s.calculate("15*2 + 1") << " = 31" << std::endl;
    std::cout << s.calculate("143+2*25-22/22 + 1") << " = 193" << std::endl;
    return 0;
}
