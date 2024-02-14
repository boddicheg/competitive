#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& A) {
        auto result = std::max_element(A.begin(), A.end());
        return std::distance(A.begin(), result);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.peakIndexInMountainArray({0, 2, 1, 0}) << std::endl;
    return 0;
}
