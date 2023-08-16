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
    bool checkRecord(string s)
    {
        return !(std::count(s.begin(), s.end(), 'A') > 1 || s.find("LLL", 0) != string::npos);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.checkRecord("PPALLP") << std::endl;
    std::cout << std::boolalpha << s.checkRecord("PPALLA") << std::endl;
    return 0;
}
