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

class Solution {
public:
    int fib(int N)
    {
        if(N < 2) return N;
        int a = 0, b = 1, c = 0;
        for(int i = 0; i < N - 1; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;     
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.fib(20);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
