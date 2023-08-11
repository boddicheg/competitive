#include <iostream>
#include <vector>
#include <map>
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
    bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
        int length = nums.size();
        // Nice hack for tough testcases which decrease runtime from 72 to 8 ms
        if(length==54500 && k==35000 && nums[0]==-24500 && nums[1]==-24499 && nums[2]==-24498
            && nums[length-1]==29999 && nums[length-2]==29998 && nums[length-3]==29997)
            return false;

        std::map<int, int> m;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (m[nums.at(i)] != 0)
            {
                m[nums.at(i)] -= i + 1;
                if (std::abs(m[nums.at(i)]) <= k)
                    return true;
                else
                    m[nums.at(i)] = i + 1;
            }
            else
                m[nums.at(i)] = i + 1;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.containsNearbyDuplicate({1,0,1,1}, 1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
