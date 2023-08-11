#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool isPrime(int num)
    {
        if (num == 1) return false;
        if (num <= 3) return true;
        for (int i = 2; i <= std::sqrt(num); ++i)
            if (num % i == 0)
                return false;
        return true;
    }

    int countPrimeSetBits(int L, int R)
    {
        int result = 0;
        for (int i = L; i <= R; ++i)
        {
            bitset<32> bmask(i);
            if(isPrime(bmask.count()))
                result++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        bool result = s.isPrime(i);
        std::cout << i << " ";
        watch(result);
    }
    std::cout << s.countPrimeSetBits(6, 10) << std::endl;
    return 0;
}
