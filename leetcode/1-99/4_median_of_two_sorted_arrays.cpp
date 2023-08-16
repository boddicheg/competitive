#include <iostream>
#include <vector>
#include <cmath>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.empty() && nums2.empty())
            return 0.0;

        std::vector<int> dst;
        std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(dst));
        if (dst.size() % 2 == 0)
        {
            size_t idx = dst.size() / 2;
            std::cout << idx << " " << dst.at(idx) << std::endl;
            return (dst.at(idx) + dst.at(idx - 1)) / 2.0;
        }
        else
            return dst.at(std::ceil(dst.size() / 2));
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    std::vector<int> v = { 1 };
    std::vector<int> v1 = { 3, 4 };
    std::cout << s.findMedianSortedArrays(v, v1) << std::endl;
    return 0;
}
