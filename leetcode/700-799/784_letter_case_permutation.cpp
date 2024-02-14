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
    vector<string> letterCasePermutation(string S)
    {
        std::vector<std::string> result;
        int n = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (isalpha(S.at(i)))
            {
                n++;
                S[i] = tolower(S[i]);
            }
        }

        int operations = 1 << n;

        for (int i = 0; i < operations; ++i)
        {
            std::string copy = S;
            for (int j = 0, k = 0; j < S.size(); ++j)
            {
                if (!isalpha(S[j])) continue;
                if (((i >> k++) & 1) == 1)
                    copy[j] = toupper(S[j]);
            }
            result.push_back(copy);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::string data = "a1b2c3";
    Solution s;
    auto result = s.letterCasePermutation(data);
    for (const auto &perm : result)
        std::cout << perm << " ";
    std::cout << std::endl;

    return 0;
}
