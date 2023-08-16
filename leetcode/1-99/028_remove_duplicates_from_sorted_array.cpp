#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

class Solution1
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int idx1 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == nums.at(idx1))
            {
                continue;
            }
            idx1++;
            nums.at(idx1) = nums.at(i);
        }
        return (nums.empty() ? 0 : idx1 + 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data = {0,0,1,1,1,2,2,3,3,4};
    Solution1 s;
    cout << s.removeDuplicates(data) << endl;
    print(data);
    return 0;
}
