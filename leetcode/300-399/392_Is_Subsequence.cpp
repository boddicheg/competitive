#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if (s.empty())
            return true;

        size_t sp = 0;
        for (size_t i = 0; i < t.size(); i++)
        {
            if (t.at(i) == s.at(sp))
            {
                sp++;
                if (sp == s.size())
                    return true;
            }
        }
        
        return sp == s.size();
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.isSubsequence("abce", "ahbgdc");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
