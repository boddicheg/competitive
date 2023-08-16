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
    string largestOddNumber(string num) {
        // string buffer;
        int i = 0;
        for (i = num.size() - 1; i >= 0; i--)
        {
            if ((num.at(i) - '0') % 2 == 1)
                break;
        }
        return string(num.begin(), num.begin() + i  + 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {};
    auto result = s.largestOddNumber("52");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
