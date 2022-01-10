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

class NumArray {
public:
    NumArray(std::vector<int>& nums) 
    : n(nums.size(), 0)
    {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums.at(i);
            n.at(i) = sum;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0)
            return n[right];

        return n[right] - n[left - 1];
    }
private:
    std::vector<int> n;
};

int main(int argc, char const *argv[])
{
    std::vector<int> v = {1,2,3,4,5}; 
    NumArray s(v);
    auto result = s.sumRange(1, 3);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
