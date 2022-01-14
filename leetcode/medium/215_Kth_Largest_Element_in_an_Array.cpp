#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> 
            pq(nums.begin(), nums.end());

        while (pq.size() > k)
            pq.pop();
        
        return pq.top();
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v {3,2,1,5,6,4};
    auto result = s.findKthLargest(v, 2);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
