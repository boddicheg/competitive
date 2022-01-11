#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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
    bool checkPerfectNumber(int num)
    {
        if (num == 1) return false;
        
        int sum = 0;
        for(int i = 1; i <=sqrt(num); i ++)
        {
            if (num % i == 0)
            {
                if (num / i != num)
                    sum += num / i;
                sum += i;
            }
        }   

        return sum == num;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.checkPerfectNumber(1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
