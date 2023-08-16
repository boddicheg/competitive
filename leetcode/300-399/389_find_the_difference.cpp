#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        std::vector<char> result;
        std::set_difference(t.begin(), t.end(), s.begin(), s.end(),
                            std::inserter(result, result.begin()));
        return result.at(0);
    }

    char findTheDifference1(string s, string t)
    {
        char result = 0;
        for (int i = 0; i < s.size(); ++i) result ^= s.at(i) ^ t.at(i);
        result ^= t.back();
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    char result = s.findTheDifference1("test", "t1set");
    watch(result);
    return 0;
}