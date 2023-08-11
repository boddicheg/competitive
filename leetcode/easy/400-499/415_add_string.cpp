#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

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
    string addStrings(string num1, string num2)
    {
        std::string result;
        int diff = std::abs((int)num1.size() - (int)num2.size());
        std::string larger = (num1.size() >= num2.size()) ? num1 : num2;
        std::string smaller = (num1.size() >= num2.size()) ? num2 : num1;

        for (int i = 0; i < diff; ++i)
            smaller = "0" + smaller;

        int carry = 0;
        for (int i = larger.size() - 1; i >= 0; --i)
        {
            int a = (larger.at(i) - '0');
            int b = (smaller.at(i) - '0');
            int sum = a + b + carry;

            if (sum > 9)
                carry = sum / 10;
            else
                carry = 0;

            result.push_back(sum % 10 + '0');
        }

        if (carry > 0)
            result.push_back(carry + '0');

        return std::string(result.rbegin(), result.rend());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << "result: " << s.addStrings("2000", "20") << std::endl;
    return 0;
}
