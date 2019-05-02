#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " -> " << (x) << std::endl

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int titleToNumber(string s)
    {
        int result = 0;
        int alph_size = 26;
        int rank = 1;
        for (int i = s.size() - 1, j = 0; i >= 0 && j < s.size(); --i, ++j)
        {
            int ascii_code = (int)(s[i]) - 65  + 1;
            result += rank * ascii_code;
            rank *= 26;
        }

        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "Z = " << std::endl << s.titleToNumber("Z") << std::endl;
    std::cout << "ZZ = " << std::endl << s.titleToNumber("ZZ") << std::endl;
    std::cout << "ZZZ = " << std::endl << s.titleToNumber("ZZZ") << std::endl;
    std::cout << "ZZZZ = " << std::endl << s.titleToNumber("ZZZZ") << std::endl;
    std::cout << "AB = " << std::endl << s.titleToNumber("AB") << std::endl;
    std::cout << "BB = " << std::endl << s.titleToNumber("BB") << std::endl;
    std::cout << "ZY = " << std::endl << s.titleToNumber("ZY") << std::endl;
    return 0;
}
