#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    string reverseString(string s)
    {
        return std::string(s.rbegin(), s.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseString("qwerty") << std::endl;
    return 0;
}
