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

int g_bad = 0;

bool isBadVersion(int version)
{
    return g_bad <= version;
}

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long left_border = 1;
        long long right_border = n;

        while(left_border < right_border)
        {
            long long guessed = left_border + (right_border - left_border) / 2.0;
            std::cout << "[" << left_border << ", " << right_border << "] guessed is " << guessed << std::endl;
            if (isBadVersion(guessed))
                right_border = guessed;
            else
                left_border = guessed + 1;
        }

        return left_border;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    g_bad = 250;
    std::cout << s.firstBadVersion(2000000) << std::endl;
    return 0;
}
