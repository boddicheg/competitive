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
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        size_t idx = nums.size() - 1;
        
        int lb = 0;
        int rb = idx;
        
        while (lb <= rb)
        {
            if (abs(nums.at(lb)) < abs(nums.at(rb)))
            {
                result[idx] = nums.at(rb) * nums.at(rb);
                rb--;
            }
            else
            {
                result[idx] = nums.at(lb) * nums.at(lb);
                lb++;
            }
            idx--;
        }
 
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1 = {-7,-3,2,3,11};
    auto result = s.sortedSquares(v1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
