#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:

    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result(nums.size(), false);

        int digit = 0;
        int mult = 0;
 
        for (size_t i = 0; i < nums.size(); i++)
        {
            digit += mult * nums.at(i);

            std::cout << mult << " = " << digit << std::endl;

            if (digit % 5 == 0)
                result.at(i) = true;

            if (mult == 0) mult = 1;
            else mult *= 2;
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {1,1,1};
    auto result = s.prefixesDivBy5(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
