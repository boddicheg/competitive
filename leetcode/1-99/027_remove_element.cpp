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
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

class Solution1
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx1 = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            nums.at(idx1) = nums.at(i);
            if (nums.at(i) != val)
            {
                idx1++;
            }
        }
        return idx1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> data = {1, 2, 1, 1, 3};
    Solution1 s;
    auto res = s.removeElement(data, 1);
    cout << res << endl;
    print(data);
    return 0;
}
