#include <iostream>
#include <vector>
#include <bitset>
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
    string addBinary(string a, string b)
    {
        std::string result;
        if (a.size() > b.size())
        {
            int size = a.size() - b.size();;
            for (int i = 0; i < size; ++i)
                b.insert(b.begin(), '0');
        }
        else if(a.size() < b.size())
        {
            int size = b.size() - a.size();
            for (int i = 0; i < size; ++i)
            {
                a.insert(a.begin(), '0');
            }
        }

        std::cout << a << " and " << b << std::endl;

        int carry = 0;
        for (int i = a.size() - 1; i >= 0; --i)
        {
            int l1 = a.at(i) == '0' ? 0 : 1;
            int l2 = 0;
            if (i < b.size())
                l2 = b.at(i) == '0' ? 0 : 1;
            else if (carry != 0)
            {
                l2 = carry;
                carry = 0;
            }
            std::cout << i << " -> " << l1 << " + " << l2 << std::endl;

            int bin_mult = 0;
            if (l1 == 1 && l2 == 1)
            {
                std::cout << "both " << carry << std::endl;
                if (carry == 1)
                    bin_mult = 1;
                else
                {
                    bin_mult = 0;
                    carry = 1;
                }
            }
            else if (l1 == 1 || l2 == 1)
            {
                std::cout << "one " << carry << std::endl;
                if (carry == 1)
                    bin_mult = 0;
                else
                {
                    bin_mult = 1;
                    carry = 0;
                }
            }
            else
            {
                if (carry == 1)
                {
                    bin_mult = 1;
                    carry = 0;
                }
                else
                    bin_mult = 0;
            }

            result.insert(result.begin(), bin_mult == 0 ? '0' : '1');
        }
        if (carry != 0)
            result.insert(result.begin(), carry == 0 ? '0' : '1');
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::cout << s.addBinary("11", "1") << std::endl;
    // std::cout << s.addBinary("1", "111") << std::endl;
    // std::cout << s.addBinary("1010", "1011") << std::endl;
    std::cout << s.addBinary("100", "110010") << std::endl;
    return 0;
}
