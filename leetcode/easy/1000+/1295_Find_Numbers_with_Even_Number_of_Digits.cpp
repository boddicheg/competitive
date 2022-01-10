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
    int ln(int n)
    {
        int l = 0;
        while (n != 0)
        {
            n /= 10;
            l++;
        }
        return l;
    }
    
    int findNumbers(vector<int>& nums) {
        int c = 0;
        for (auto d: nums)
        {
            if (ln(d) % 2 == 0)
                c++;
        }
        return c;
        
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1 {555,901,482,1771};
    auto result = s.findNumbers(v1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
