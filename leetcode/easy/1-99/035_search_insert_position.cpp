#include <iostream>
#include <vector>
#include <cmath>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        long long left_border = 0;
        long long right_border = nums.size() - 1;

        long long guessed = -1;
        while (left_border <= right_border)
        {
            guessed = left_border + (right_border - left_border) / 2.0;
            // std::cout << "[" << left_border << ", " << right_border << "] guessed is " << guessed << std::endl;
            if (target > nums.at(guessed))
                left_border = guessed + 1;
            else
                right_border = guessed - 1;
        }
        return left_border;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {1, 3, 5, 6};
    std::cout << s.searchInsert(v, 0) << std::endl;
    return 0;
}
