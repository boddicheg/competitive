#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;

        char table[256] = {0};
        for(const auto& e: s)
            table[e]++;

        for(const auto& e: t)
        {
            table[e]--;
        }

        for (const auto& e: table)
            if(e > 0)
                return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.isAnagram("rat", "car") << std::endl;
    std::cout << std::boolalpha << s.isAnagram("rac", "car") << std::endl;
    std::cout << std::boolalpha << s.isAnagram("rca", "car") << std::endl;
    return 0;
}
