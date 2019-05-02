#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool isUgly(int num)
    {
        if(num == 0) return false;
        while (num != 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 5 == 0)
                num /= 5;
            else
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << boolalpha << s.isUgly(6) << std::endl;
    std::cout << boolalpha << s.isUgly(8) << std::endl;
    std::cout << boolalpha << s.isUgly(14) << std::endl;
    return 0;
}
