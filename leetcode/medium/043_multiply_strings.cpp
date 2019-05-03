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

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        std::string result;

        vector<int> mults(num1.size() + num2.size(), 0);

        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int tmp = mults.at(i + j + 1) + ((num1.at(i) - '0') * (num2.at(j) - '0')) + carry;
                mults.at(i + j + 1) = tmp % 10;
                carry = tmp / 10;
            }
            mults.at(i) += carry;
        }

        bool stillzero = true;
        for (int i = 0; i < mults.size(); ++i)
        {
            if (stillzero && mults.at(i) == 0)
                continue;
            else
            {
                stillzero = false;
                result.push_back(mults.at(i) + '0');
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::cout << s.multiply("2", "3") << std::endl;
    std::cout << s.multiply("123", "456") << std::endl;
    // std::cout << s.multiply("100", "1000") << std::endl;
    return 0;
}
