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
    vector<int> findErrorNums(vector<int> &nums)
    {
        std::vector<int> result;
        std::sort(nums.begin(), nums.end());
        print(nums);
        int practical = 0;
        for (const auto &e : nums)
            practical += e;
        int theoretical = (int)nums.size() * (1 + nums.at(nums.size() - 1)) / 2.0;
        std::cout << theoretical << " " << practical << std::endl;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums.at(i) == nums.at(i - 1))
                result.push_back(nums.at(i));
        }
        int diff = theoretical - practical;
        // kludge 1
        if(diff == 0)
            diff = 1;
        // kludge 2
        int second = result.at(0) + diff;
        if(std::find(nums.begin(), nums.end(), second) != nums.end())
            second = nums.at(nums.size() - 1) + 1;
        result.push_back(second);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {1, 1, 3, 4};
    // std::vector<int> data = {1, 1};
    // std::vector<int> data = {2, 2};
    // std::vector<int> data = {3, 2, 3, 4, 6, 5};
    // std::vector<int> data = {1, 2, 3, 4, 6, 6};
    std::vector<int> data = {1,5,3,2,2,7,6,4,8,9};

    print(s.findErrorNums(data));
    return 0;
}
