#include <iostream>
#include <vector>
#include <unordered_set>
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
    bool checkIfExist(vector<int>& arr) {
        int size = arr.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                    return true;
            }
            
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v1 {-2,0,10,-19,4,6,-8};
    auto result = s.checkIfExist(v1);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
