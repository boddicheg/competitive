#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

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
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        std::stringstream ss(paragraph);
        std::string result;
        std::map<std::string, int> table;

        std::string buffer;
        while (std::getline(ss, buffer, ' '))
        {
            std::transform(buffer.begin(), buffer.end(),  buffer.begin(), ::tolower);
            buffer.erase(std::remove_if(buffer.begin(), buffer.end(), [] (unsigned char c)
            {
                return std::ispunct(c);
            }), buffer.end());

            if (std::find(banned.begin(), banned.end(), buffer) == banned.end())
            {
                table[buffer]++;
            }
        }

        auto x = std::max_element(table.begin(), table.end(), [](const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) {
            return (p1.second < p2.second);
        });
        return x->first;
    }
};

int main(int argc, char const *argv[])
{
    std::string data = "Bob hit a ball, the hit BALL flew far after it was hit.";
    std::vector<std::string> banned = { "hit" };
    Solution s;
    std::cout << s.mostCommonWord(data, banned) << std::endl;
    return 0;
}
