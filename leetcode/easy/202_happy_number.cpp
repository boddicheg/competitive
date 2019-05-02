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
    int sum_of_sq(int n)
    {
        int result = 0;
        while(n != 0)
        {
            int digit = n % 10;
            n /= 10;
            result += digit * digit;
        }
        return result;
    }

    bool isHappy(int n)
    {
        int counter = 0;
        while(n != 1 && counter != 20)
        {
            n = sum_of_sq(n);
            std::cout << n << std::endl;
            counter++;
        }
        return n == 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << std::boolalpha << s.isHappy(199) << std::endl;
    return 0;
}
