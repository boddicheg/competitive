#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

std::vector<std::string> morse_codes {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

class Solution
{
public:
    int uniqueMorseRepresentations(const vector<string> &words)
    {
        int start_code = 97;
        for (const auto &code : morse_codes)
            m_translate[start_code++] = code;

        std::set<std::string> uniq;
        for (const auto &word : words)
        {
            std::string converted;
            for (const auto &letter : word)

                converted += m_translate[(int)letter];
            uniq.insert(converted);
        }
        return uniq.size();
    }
private:
    std::map<int, std::string> m_translate;
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.uniqueMorseRepresentations({"gin", "zen", "gig", "msg"}) << std::endl;
    return 0;
}
