#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        std::bitset<32> bs(n);
        std::string bits = bs.to_string();
        std::cout << bits << std::endl;
        bits.erase(0, bits.find_first_not_of('0'));
        char prev = '2';

        for (int i = bits.size() - 1; i >= 0; --i)
        {

            if (prev == '2')
            {
                prev = bits.at(i);
                continue;
            }

            if (prev == bits.at(i))
                return false;
            else
                prev = bits.at(i);
        }
        return true;
    }

    bool hasAlternatingBits1(int n)
    {
        n ^= (n >> 1);
        return (n & (n + 1)) ? false : true;
    }
};



int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 15; ++i)
    {
        std::cout << i << " " << std::boolalpha << s.hasAlternatingBits1(i) << std::endl;
    }
    return 0;
}