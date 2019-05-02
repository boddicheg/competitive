#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        std::map<int, int> m;
        for(const auto &e: nums)
            m[e]++;

        auto x = std::max_element(m.begin(), m.end(), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
            return (p1.second < p2.second);
        });
        return x->first;
    }
};

int main(int argc, char const *argv[])
{
    // std::vector<int> data = {2,2,1,1,1,2,2};
    std::vector<int> data = {3, 2, 3};
    Solution s;
    std::cout << s.majorityElement(data) << std::endl;
    return 0;
}
