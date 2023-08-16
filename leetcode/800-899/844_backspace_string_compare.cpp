#include <iostream>
#include <vector>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    void clean(std::string &S)
    {
        std::stack<char> s1;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S.at(i) == '#')
            {
                if(!s1.empty())
                    s1.pop();
            }
            else
                s1.push(S.at(i));
        }

        S = "";
        while (!s1.empty())
        {
            char t = s1.top();
            if(t != '#')
                S += t;
            s1.pop();
        }
    }

    bool backspaceCompare(string S, string T)
    {
        if (S == T)
            return true;
        clean(S);
        clean(T);
        // std::cout << S << " " << T << std::endl;
        return S == T;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.backspaceCompare("ab#c", "ad#c") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("ab##", "c#d#") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("a##c", "#a#c") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("a#c", "b") << std::endl;
    std::cout << std::boolalpha << s.backspaceCompare("y#fo##f", "y#f#o##f") << std::endl;
    return 0;
}
