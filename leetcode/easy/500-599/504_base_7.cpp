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

class Solution {
public:
    string convertToBase7(int num)
    {
        if (num == 0)
            return "0";
        bool sign = false;

        if(num < 0)
        {
            sign = true;
            num = abs(num);
        }
        std::string result;
        while(num != 0)
        {
            int r = num % 7;
            result = to_string(r) + result;
            num /= 7;
        }
        if(sign)
            result = "-" + result;

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.convertToBase7(384605) << std::endl;
    std::cout << s.convertToBase7(0) << std::endl;
    std::cout << s.convertToBase7(-10) << std::endl;
    return 0;
}
