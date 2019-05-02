#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        if (haystack.empty() || needle.size() > haystack.size()) return -1;

        int idx = -1;

        for (int i = 0; i < haystack.size(); ++i)
        {
            // Remove
            if (idx == -1 && i + needle.size() > haystack.size())
                return -1;

            if (haystack.at(i) == needle.at(0))
                idx = i;

            for (int j = 0; j < needle.size(); ++j)
            {
                if (needle.at(j) != haystack.at(i + j))
                {
                    idx = -1;
                    break;
                }
            }
            if (idx != -1)
                break;
        }

        return idx;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.strStr("hello world", "rld") << std::endl;
    std::cout << s.strStr("aaaaa", "baa") << std::endl;
    return 0;
}
