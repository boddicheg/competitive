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
    int countBinarySubstrings(string s)
    {
        int result = 0;
        int count = 1;
        int previous = 0;
        for (int i = 1; i <= s.size(); ++i)
        {
            if(s[i] == s[i - 1])
                count++;
            else
            {
                result += std::min(previous, count);
                previous = count;
                count = 1;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.countBinarySubstrings("10101") << std::endl;
    std::cout << s.countBinarySubstrings("00110011") << std::endl;
    return 0;
}
