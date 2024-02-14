#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::unordered_map<std::string, int> s2i;
        std::unordered_map<char, int> p2i;
        std::stringstream ss(s);
        int i = 0;
        for(std::string word; ss >> word; ++i)
        {
            if (s2i[word] != p2i[pattern[i]])
                return false;
            s2i[word] = i + 1;
            p2i[pattern[i]] = i + 1;
        }

        return i == pattern.size();
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.wordPattern("abba", "dog cat cat dog");
    std::cout << "Result: " << result << std::endl;
    result = s.wordPattern("abba", "dog cat cat fish");
    std::cout << "Result: " << result << std::endl;
    result = s.wordPattern("aaaa", "dog cat cat dog");
    std::cout << "Result: " << result << std::endl;
    result = s.wordPattern("abba", "dog dog dog dog");
    std::cout << "Result: " << result << std::endl;
    result = s.wordPattern("aaaa", "dog dog dog dog");
    std::cout << "Result: " << result << std::endl;
    result = s.wordPattern("jquery", "jquery");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
