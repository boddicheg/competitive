#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_streak = 0;
        std::map<char, int> streak;
        int j = 0, i = 0;
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            char letter = s.at(i);
            auto p = streak.find(letter);

            if(p != streak.end())
            {
                j = std::max(p->second, j);
            }
            max_streak = std::max(max_streak, i - j + 1);
            streak[letter] = i + 1;
        }

        return max_streak;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::cout << "pwwkew -> " << s.lengthOfLongestSubstring("pwwkew") << std::endl;
    // std::cout << "abcabcbb -> " << s.lengthOfLongestSubstring("abcabcbb") << std::endl;
    // std::cout << "bbbbb -> " << s.lengthOfLongestSubstring("bbbbb") << std::endl;
    // std::cout << "c -> " << s.lengthOfLongestSubstring("c") << std::endl;
    std::cout << "dvdf -> " << s.lengthOfLongestSubstring("dvdf") << std::endl;
    // std::cout << "scdsclsvldkdfkfkfkf -> " << s.lengthOfLongestSubstring("scdsclsvldkdfkfkfkf") << std::endl;
    // std::cout << "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ -> "
    //           << s.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~") << std::endl;

    return 0;
}