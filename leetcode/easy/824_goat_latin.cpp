#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

std::set<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

class Solution
{
public:
    string toGoatLatin(string S)
    {
        std::string result;
        std::string word_ending = "a";
        char word_ending_inc = 'a';

        std::stringstream ss(S);
        std::string word;
        while(std::getline(ss, word, ' '))
        {
            char first_letter = word.at(0);
            if(vowel.find(first_letter) == vowel.end())
            {
                word.erase(0, 1);
                word += first_letter;
            }
            word += "ma";
            word += word_ending;
            word_ending +=word_ending_inc;

            result += word + " ";
        }
        result.erase(result.size() - 1, 1);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.toGoatLatin("I speak Goat Latin");
    std::cout << result << std::endl;
    return 0;
}