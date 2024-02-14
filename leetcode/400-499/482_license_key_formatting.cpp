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
    string licenseKeyFormatting(string S, int K)
    {
        std::string formatted;

        for (int i = S.size() - 1, idx = 1; i >= 0; --i)
        {
            if (S.at(i) != '-')
            {
                formatted += std::toupper(S.at(i));
                if (idx == K)
                {
                    std::cout << i << std::endl;
                    formatted += "-";
                    idx = 1;
                }
                else
                    idx++;
            }
        }
        formatted =  std::string(formatted.begin() + formatted.find_first_not_of('-'), formatted.begin() + formatted.find_last_not_of('-') + 1);
        return { formatted.rbegin(), formatted.rend() };
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << std::endl;
    std::cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 2) << std::endl;
    std::cout << s.licenseKeyFormatting("5F3Z-2e-9-w-dv-dfdler", 8) << std::endl;
    std::cout << s.licenseKeyFormatting("2-5g-3-J", 2) << std::endl;
    std::cout << s.licenseKeyFormatting("2-4A0r7-4k", 4) << std::endl;
    std::cout << s.licenseKeyFormatting("--a-a-a-a--", 2) << std::endl;
    return 0;
}
