#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

// 100% lol runtime but 10% memory
class Solution0 {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        for (size_t i = m, j = 0; i < nums1.size(); i++, j++)
            nums1.at(i) = nums2.at(j);
        std::sort(nums1.begin(), nums1.end());
    }
};

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1.at(i) > nums2.at(j))
            {
                nums1.at(k) = nums1.at(i);
                k--;
                i--;
            }
            else
            {
                nums1.at(k) = nums2.at(j);
                k--;
                j--;
            }
        }

        while (i >= 0)
            nums1.at(k--) = nums1.at(i--);
        while (j >= 0)
            nums1.at(k--) = nums2.at(j--);

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v1 = {1,2,3,0,0,0};
    std::vector<int> v2 = {2,5,6};
    s.merge(v1, 3, v2, 3);
    std::cout << "Result: " << v1 << std::endl;
    return 0;
}
