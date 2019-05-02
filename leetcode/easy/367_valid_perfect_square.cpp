#include <iostream>
#include <vector>
#include <cmath>
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
    bool isPerfectSquare(int num)
    {
        int left_border = 1;
        int right_border = num;
        int middle;
        while (left_border <= right_border)
        {
            middle = left_border + (right_border - left_border) / 2.0;
            if (middle > num / middle)
                right_border = middle - 1;
            else if (middle < num / middle)
                left_border = middle + 1;
            else
                return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 1000; ++i)
    {
        std::cout << "i = " << i * i << " " << std::boolalpha << s.isPerfectSquare(i * i) << std::endl;
    }
    return 0;
}
