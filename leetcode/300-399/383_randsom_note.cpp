#include <iostream>
#include <vector>
#include <set>
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
    bool canConstruct(string ransomNote, string magazine)
    {
        int table[256] = {0};
        for(const auto& e : magazine)
            table[e]++;

        for(const auto& e: ransomNote)
        {
            table[e]--;
            if(table[e] < 0)
                return false;
        }

        return  true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    std::cout << std::boolalpha << s.canConstruct("a", "b") << std::endl;
    return 0;
}
