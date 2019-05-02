#include <iostream>
#include <vector>
#include <cmath>
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
    bool isPrime(int n)
    {
        if (n == 1 || n == 4) return false;
        if (n == 2 || n == 3 || n == 5) return true;
        for (int i = 2; i <= std::sqrt(n); ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimes(int n)
    {
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            if (isPrime(i))
                count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.countPrimes(2) << std::endl;
    return 0;
}
