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
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        if (duration == 0) return 0;
        if (timeSeries.size() == 1) return duration;

        int result = 0;
        int start = timeSeries.at(0);
        int end = start + duration; 
        for(int i = 1; i < timeSeries.size(); i ++)
        {
            if (timeSeries.at(i) > end)
            {
                result += end - start;
                start = timeSeries.at(i);
            }
            end = timeSeries.at(i) + duration;
        }
        result += end - start;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v {1,2,3,4,5};
    // std::vector<int> v {1, 2};
    auto result = s.findPoisonedDuration(v, 5);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
