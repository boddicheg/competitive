#include <iostream>
#include <vector>
#include <string>
#include <set>
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
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp = [](std::string& left, std::string& right) 
        {
            if (left.size() != right.size())
                return left.size() > right.size();

            for(int i = 0; i < left.size(); i ++ )
            {
                int l = left.at(i) - '0';
                int r = right.at(i) - '0';
                if (l != r)
                {
                    return l > r;
                }
            } 
        };
        std::priority_queue<std::string, std::vector<std::string>, decltype(cmp)> 
            pq(nums.begin(), nums.end(), cmp);
        while (pq.size() > k)
            pq.pop();
        
        return pq.top();
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v {};
    auto result = s.template(..);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
