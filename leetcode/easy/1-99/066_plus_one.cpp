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
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;

        digits.at(digits.size() - 1) += 1;

        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            int result = *(it) + carry;

            if (result > 9)
            {
                *(it) = result % 10;
                carry = result / 10;
            }
            else
            {
                *(it) = result;
                carry = 0;
                break;
            }
        }

        if (carry > 0)
            digits.insert(digits.begin(), carry);

        return digits;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data = { 9, 9, 9, 9};
    // std::vector<int> data = { 8, 9, 9, 9};
    // std::vector<int> data = { 0 };
    Solution s;
    auto result = s.plusOne(data);
    print(data);
    return 0;
}
