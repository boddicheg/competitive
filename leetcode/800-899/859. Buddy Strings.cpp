#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
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
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;

        if (s == goal)
        {
            int a[26] = {0};
            for(char e: goal)
            {
                a[e - 'a'] ++;
                if (a[e - 'a'] > 1)
                    return true;
            }
            return false;
        }

        int k = -1;
        for (size_t i = 0; i < goal.size(); i++)
        {
            if (s.at(i) != goal.at(i))
            {
                k = i;
                break;
            }
        }
        int j = -1;
        int count = 0;
        for (size_t i = k + 1; i < goal.size(); i++)
        {
            if (s.at(i) != goal.at(i))
            {
                j = i;
                count ++;
            }
        }

        if (count > 1 || j == -1) return false;

        return (s.at(k) == goal.at(j)) && (s.at(j) == goal.at(k));
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.buddyStrings("ac", "ac");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
