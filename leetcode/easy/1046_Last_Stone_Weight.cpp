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

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones)
    {
        auto find_max_and_delete = [&stones]()
        {
            auto max = std::max_element(stones.begin(), stones.end());
            int max_elem = *(max);
            stones.erase(max);
            return max_elem;
        };

        while (stones.size() > 1)
        {
            int first_max = find_max_and_delete();
            int second_max = find_max_and_delete();
            if (first_max != second_max)
            {
                stones.push_back(std::abs(first_max - second_max));
            }
        }
        

        return (!stones.empty()) ? stones.at(0) : 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> data {2,7,5,1,8,1};
    auto result = s.lastStoneWeight(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
