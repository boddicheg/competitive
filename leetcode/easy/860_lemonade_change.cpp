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
    bool lemonadeChange(vector<int> &bills)
    {
        int fivs_count = 0;
        int tens_count = 0;

        for (const auto &e : bills)
        {
            if (e == 5)
                fivs_count++;
            else if (e == 10)
            {
                if (fivs_count > 0)
                {
                    fivs_count--;
                    tens_count++;
                }
                else
                    return false;
            }
            else
            {
                // 20 => 10 + 5 or 5 + 5 + 5
                if (fivs_count >= 1 && tens_count >= 1)
                {
                    fivs_count--;
                    tens_count--;
                }
                else if (fivs_count >= 3)
                    fivs_count -= 3;
                else
                    return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data1 = { 5, 5, 10, 10, 20}; // false
    std::vector<int> data2 = { 5, 5, 5, 10, 20}; // true
    std::vector<int> data3 = { 5, 5, 10 }; // true
    std::vector<int> data4 = { 10, 10 }; // false
    Solution s;
    std::cout << s.lemonadeChange(data1) << std::endl;
    std::cout << s.lemonadeChange(data2) << std::endl;
    std::cout << s.lemonadeChange(data3) << std::endl;
    std::cout << s.lemonadeChange(data4) << std::endl;
    return 0;
}
