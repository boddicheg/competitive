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
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> result;
        for (int h = 0; h < 12; ++h)
        {
            for (int m = 0; m < 60; ++m)
            {
                bitset<10> bs(h << 6 | m);
                if (bs.count() == num)
                {
                    // std::cout << h << ":" << ((m < 10) ? "0" : "") << m << " is " << bs.to_string() << std::endl;
                    std::string time = std::to_string(h) + ":" + ((m < 10) ? "0" : "") + std::to_string(m);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.readBinaryWatch(1);
    print(result);
    return 0;
}
