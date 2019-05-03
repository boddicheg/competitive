#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<std::string, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        std::unordered_map<std::string, int> table;
        vector<string> result;
        std::string buffer;
        std::stringstream ss;
        ss << A << " " << B;
        while (std::getline(ss, buffer, ' '))
            table[buffer] ++;

        for (const auto &e : table)
            if (e.second == 1)
                result.push_back(e.first);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    print(s.uncommonFromSentences("this apple is sweet", "this apple is sour"));
    return 0;
}
