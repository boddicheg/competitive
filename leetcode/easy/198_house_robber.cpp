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

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int rob = 0;
        int norob = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmp = norob + nums.at(i);
            norob = std::max(rob, norob);
            rob = tmp;
        }
        return std::max(rob, norob);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {2,7,9,3,1};
    // std::vector<int> data = {1,2,3,3};
    std::vector<int> data = {2,1,1,2};
    std::cout << s.rob(data) << std::endl;
    return 0;
}
