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
    bool isVowel(char c)
    {
        return c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u'
            || c == 'A' || c == 'O' || c == 'E' || c == 'I' || c == 'U';
    }

    string reverseVowels(string s)
    {
        for (int i = 0; i < s.size(); ++i)
        {
            if (isVowel(s.at(i)))
                std::cout << s.at(i) << "[" << i << "]";
            else
                std::cout << s.at(i);
        }
        std::cout << std::endl;

        int latest_right = s.size() - 1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (!isVowel(s.at(i)))
                continue;

            for (int j = latest_right; j >= 0; --j)
            {
                if (i >= j)
                    return s;

                if (!isVowel(s.at(j)))
                    continue;
                std::cout << " indexes: " << i << " <-> " << j << std::endl;
                std::swap(s.at(i), s.at(j));
                latest_right = --j;
                break;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::cout << s.reverseVowels("hello") << std::endl;
    // std::cout << s.reverseVowels("leetcode") << std::endl;
    // std::cout << s.reverseVowels("LEETCODE") << std::endl;
    // std::cout << s.reverseVowels("ae") << std::endl;
    // std::cout << s.reverseVowels("aA") << std::endl;
    std::cout << s.reverseVowels("Marge, let's \"went.\" I await news telegram.") << std::endl;
    // std::cout << s.reverseVowels("aaaaeeee") << std::endl;
    return 0;
}
