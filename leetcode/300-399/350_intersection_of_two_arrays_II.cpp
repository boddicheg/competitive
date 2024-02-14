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
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int> result;

        std::set_intersection(nums1.begin(), nums1.end(),
                              nums2.begin(), nums2.end(), std::back_inserter(result));
        return result;
    }
};

class Solution2
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        std::map<int, int> m;
        std::vector<int> result;

        for (const auto e: nums1)
            m[e]++;

        for (const auto e: nums2)
            if (--m[e] >= 0)
                result.push_back(e);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<int> data1 = { 1, 2, 2, 1 };
    std::vector<int> data2 = { 2, 2 };
    Solution2 s;
    auto result = s.intersect(data1, data2);
    print(result);
    return 0;
}
