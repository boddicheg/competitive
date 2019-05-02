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
    string reverseStr(string s, int k)
    {
        if (s.size() >= k && s.size() < 2 * k)
            std::reverse(s.begin(), s.begin() + k);
        else
            for (size_t i = 0; i < s.size(); i += 2 * k)
            {
                size_t left = i;
                size_t right = i + k;
                if (right >= s.size())
                    right = s.size();
                std::cout << std::string(s.begin() + left, s.begin() + right) << std::endl;
                std::reverse(s.begin() + left, s.begin() + right);
            }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.reverseStr("abcdefg", 2) << std::endl;
    std::cout << s.reverseStr("abcdkxckzxcaowskdsdkjsbcsndncefg", 3) << std::endl;
    return 0;
}
