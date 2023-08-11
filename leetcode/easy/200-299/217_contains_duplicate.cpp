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
    bool containsDuplicate(vector<int> &nums)
    {
        std::map<int, int> table;
        for(const auto& e: nums)
        {
            table[e]++;
            if(table[e] > 1)
                return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
