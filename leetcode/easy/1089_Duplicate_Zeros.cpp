#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

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
    void duplicateZeros(std::vector<int> &arr)
    {
        int n = arr.size();
        int j = n + std::count(arr.begin(), arr.end(), 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if(--j < n)
                arr.at(j) = arr.at(i);
            if(arr.at(i) == 0 && --j < n)
                arr.at(j) = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {1,0,2,3,0,4,5,0};
    std::vector<int> data = {1,2,3};
    s.duplicateZeros(data);
    std::cout << "Result: " << data << std::endl;
    return 0;
}
