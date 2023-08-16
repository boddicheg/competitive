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
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;

        sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> result;

        int start = intervals.at(0).at(0);
        int end = intervals.at(0).at(1);

        for(int i = 1; i < intervals.size(); i ++)
        {
            auto interval = intervals.at(i);
            if (interval.at(0) <= start)
                start = interval.at(0);

            if (end >= interval.at(0))
            {
                if (end < interval.at(1))
                    end = interval.at(1);
            }
            else
            {
                // new interval
                result.push_back({start, end});
                start = interval.at(0);
                end = interval.at(1);
            }

        }
        result.push_back({start, end});
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<std::vector<int>> v {{1,3},{2,6},{8,10},{15,18}};
    std::vector<std::vector<int>> v {{1,4},{0,0}};
    auto result = s.merge(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
