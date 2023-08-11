#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <queue>
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
    int findDuplicate1(vector<int>& nums) {
        std::unordered_set<int> s;
        for(auto &&e: nums)
        {
            if (s.count(e) > 0)
                return e;
            s.insert(e);
        }
        return -1;
    }

    int findDuplicate(vector<int>& nums) {

        for (size_t i = 0; i < nums.size(); i++)
        {
            int curr = abs(nums.at(i));
            if (nums.at(curr) < 0)
                return curr;
            nums.at(curr) *= -1;
        }
        return - 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> v {1,3,4,2,4};
    vector<int> v {2,2,2,2,2,2};
    auto result = s.findDuplicate(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
