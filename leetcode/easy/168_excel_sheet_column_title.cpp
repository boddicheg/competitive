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
    string convertToTitle(int n)
    {
        std::string result;
        while(n > 0)
        {
            n -= 1;
            char l = 'A' +  n % 26;
            n /= 26;
            result = l + result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.convertToTitle(701) << std::endl;
    return 0;
}
