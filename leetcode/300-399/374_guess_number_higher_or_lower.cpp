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

int g_guessed = 0;

int guess(int num)
{
    if (num < g_guessed)
        return 1;
    else if (num > g_guessed)
        return -1;
    else
        return 0;
}

class Solution
{
public:
    int guessNumber(int n)
    {
        long long left_border = 1;
        long long right_border = n;

        if(guess(n) == 0)
            return n;

        while (true)
        {
            std::cout << "[" << left_border << ", " << right_border << "]" << std::endl;
            long long guessed = (left_border + right_border) / 2.0;
            int result = guess(guessed);
            if (result == 0)
                return guessed;
            else if (result == 1)
                left_border = guessed;
            else
                right_border = guessed;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    g_guessed = 1702766719;
    std::cout << s.guessNumber(2126753390) << std::endl;
    return 0;
}
