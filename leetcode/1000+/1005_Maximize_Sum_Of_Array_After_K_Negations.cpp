#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    int largestSumAfterKNegations(std::vector<int> &A, int K)
    {
        int sum = std::accumulate(A.begin(), A.end(), 0);
        // 2 times faster that std::multiset<int>
        std::priority_queue<int, std::vector<int>, std::greater<int> > table(A.begin(), A.end());
        for (size_t i = 0; i < K; i++)
        {
            auto value = table.top();
            table.pop();
            sum -= value;
            value *= -1;
            sum += value;
            table.push(value);
        }

        return sum;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> data = {
        // 4, 2, 3
        // 3,-1,0,2
        2,-3,-1,5,-4
    };
    // int K = 1;
    // int K = 3;
    int K = 2;
    auto result = s.largestSumAfterKNegations(data, K);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
