#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::string reverseOnlyLetters(std::string S)
    {
        std::string result(S);
        for (int i = S.size() - 1, j = 0; i >= 0;)
        {
            if(!std::isalpha(S.at(i)))
            {
                i--;
                continue;
            }

            if(!std::isalpha(S.at(j)))
            {
                j++;
                continue;
            }

            if (std::isalpha(S.at(j)) && std::isalpha(S.at(i)))
            {
                result.at(j) = S.at(i);
                i--;
                j++;
            }  
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::string data = "Test1ng-Leet=code-Q!";
    std::string data = "a-bC-dEf-ghIj";
    auto result = s.reverseOnlyLetters(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
