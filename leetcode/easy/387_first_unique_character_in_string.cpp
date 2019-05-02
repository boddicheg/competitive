#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int firstUniqChar(string s)
    {
        std::map<char, int> table;

        for(const auto& c: s)
            table[c]++;

        int result = std::numeric_limits<int>::max();
        for(const auto& rec: table)
            if(rec.second == 1)
            {
                // get index of chr
                // std::cout << rec.first << std::endl;
                result = std::min((int)s.find_first_of(rec.first), result);
            }

        return result > s.size() ? -1 : result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.firstUniqChar("") << std::endl;
    return 0;
}
