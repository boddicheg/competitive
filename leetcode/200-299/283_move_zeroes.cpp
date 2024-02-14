#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

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

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t size = nums.size();
        for(size_t i = 0; i < size; i++)
        {
            if(nums.at(i) == 0)
            {
                auto it = nums.begin() + i;
                std::rotate(it, it + 1, nums.end());
                i--;
                size--;
            }
        }
    }
};

class Solution1
{
public:
    void moveZeroes(vector<int>& nums)
    {
        size_t size = nums.size();
        size_t j = 0;
        for(size_t i = 0; i < size; i++)
        {
            if (nums.at(i) != 0)
                nums.at(j++) = nums.at(i);
        }

        for(size_t i = j; i < size; i++)
        {
            nums.at(i) = 0;
        }
    }
};


int main(int argc, char const *argv[])
{
    std::vector<int> data = { 1, 0, 2, 0, 0, 1};
    Solution1 s;
    s.moveZeroes(data);
    std::cout << data << std::endl;
    return 0;
}
