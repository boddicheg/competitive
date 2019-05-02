#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl;
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool wordPattern(string pattern, string str)
    {
        std::map<char, std::string> bijection;
        std::stringstream ss(str);
        std::string buffer;

        for (int i = 0; i < pattern.size(); ++i)
        {
            char p = pattern.at(i);
            std::getline(ss, buffer, ' ');
            std::cout << p << " -> " << buffer << std::endl;
            auto it = bijection.find(p);
            if (it != bijection.end())
            {
                watch(it->first);
                watch(buffer);
                watch(it->second == buffer);
                if (it->second != buffer)
                    return false;
            }
            else
            {
                bijection[p] = buffer;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.wordPattern("abba", "dog cat cat dog")  << std::endl;
    std::cout  << std::boolalpha << s.wordPattern("abba", "dog cat cat fish")  << std::endl;
    std::cout  << std::boolalpha << s.wordPattern("aaaa", "dog cat cat dog")  << std::endl;
    std::cout  << std::boolalpha << s.wordPattern("abba", "dog dog dog dog")  << std::endl;
    return 0;
}
