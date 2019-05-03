#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::string rshift(const std::string &input)
    {
        std::string result;
        result += input.at(input.size() - 1);
        result.append(input.begin(), input.begin() + input.size() - 1);
        return result;
    }

    bool rotateString(string A, string B)
    {
        if (A.size() != B.size()) return false;

        if (A == B) return true;

        bool result = false;
        std::string current = A;
        for (int i = 0; i < A.size(); ++i)
        {
            if (current == B)
                return true;

            current = rshift(current);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.rotateString("abcde", "cdeab") << std::endl;
    return 0;
}
