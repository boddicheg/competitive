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
    bool isGoodDigit(int d)
    {
        return d == 2 || d == 5 || d == 6 || d == 9 || d == 0 || d == 1 || d == 8;
    }

    int rotate(int num)
    {
        switch (num)
        {
        case 1: return 1;
        case 0: return 0;
        case 8: return 8;
        case 2: return 5;
        case 5: return 2;
        case 6: return 9;
        case 9: return 6;
        }
        return 0;
    }

    int rotatedDigits(int N)
    {
        int result = 0;
        for (int i = 1; i <= N; ++i)
        {
            int carry = i;
            bool isGoodNum = true;
            while (carry != 0)
            {
                if (!isGoodDigit(carry % 10))
                {
                    isGoodNum = false;
                    break;
                }
                carry /= 10;
            }

            int rotated = 0;
            carry = i;
            int multiplier = 1;
            while (carry != 0)
            {
                rotated = rotated + rotate(carry % 10) * multiplier;
                carry /= 10;
                multiplier *= 10;
            }

            if (isGoodNum && i != rotated)
                result++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.rotatedDigits(30) << std::endl;
    return 0;
}
