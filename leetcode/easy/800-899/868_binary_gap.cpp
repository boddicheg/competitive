#include <iostream>
#include <vector>
#include <bitset>
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
    ss << "[ " << p.first << ", " << p.first << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int binaryGap(int N)
    {
        std::bitset<32> bs(N);
        std::string string_repr = bs.to_string();
        std::cout << string_repr << std::endl;
        int max_gap = std::numeric_limits<int>::min();
        int current_gap = 0;
        int ones = 0;
        for(const auto& e: string_repr)
        {
            if(e == '0')
            {
                if(current_gap == 0)
                    continue;
                else
                    current_gap++;
            }
            else
            {
                ones++;
                if(current_gap == 0)
                    current_gap++;
                else
                {
                    max_gap = std::max(max_gap, current_gap);
                    // std::cout << max_gap << " ";
                    current_gap = 1; //mb 1
                }
            }
        }
        if (ones <= 1)
            return 0;
        return max_gap;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for (int i = 0; i < 100; ++i)
    {
        std::cout << s.binaryGap(i) << std::endl;
    }
    return 0;
}
