#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T& container)
{
    std::cout << "[";
    for(const auto& e: container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::map<int, int> pairs;

        for (size_t i = 0; i < numbers.size(); ++i)
        {
            int first = numbers.at(i);
            auto it = pairs.find(target - first);
            if (it != pairs.end() && it->second != i)
                return {it->second + 1, (int)i + 1};
            else
                pairs[first] = i;
        }
        return {};
    }
};

int main(int argc, char const *argv[])
{
    vector<int> numbers = {2,7,11,15};
    Solution s;
    auto result = s.twoSum(numbers, 9);
    print(result);
    return 0;
}
