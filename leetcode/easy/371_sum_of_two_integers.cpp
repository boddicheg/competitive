#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int getSum(int a, int b)
    {
        int s = a ^ b;
        int carry = a & b;

        if (carry == 0) return s;
        else return getSum(s, carry << 1);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
