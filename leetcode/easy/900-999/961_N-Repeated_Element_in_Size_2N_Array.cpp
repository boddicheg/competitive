#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

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

// Runtime: 16 ms, faster than 100.00% of C++ online submissions for N-Repeated Element in Size 2N Array.
// Memory Usage: 10.8 MB, less than 99.68% of C++ online submissions for N-Repeated Element in Size 2N Array.
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int repeatedNTimes(const std::vector<int>& A)
    {
        for(size_t i = 0; i < A.size(); i++)
        {
            for(size_t j = i + 1; j < A.size(); j++)
            {
                if (A.at(i) == A.at(j))
                    return A.at(i);
            }
        }
        return -1;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    auto result = s.repeatedNTimes({1,2,3,3});
    // auto result1 = s.repeatedNTimes({2,1,2,5,3,2});
    // auto result2 = s.repeatedNTimes({5,1,5,2,5,3,5,4});

    std::cout << result << std::endl;
    return 0;
}
