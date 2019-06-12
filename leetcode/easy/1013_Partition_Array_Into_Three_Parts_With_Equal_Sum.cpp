#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

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
    bool canThreePartsEqualSum(std::vector<int> &A)
    {
        int sum = std::accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0)
            return false;

        int chunk_sum = sum / 3;
        int buffer = 0;
        int count_of_chunks = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            buffer += A.at(i);
            if (buffer == chunk_sum)
            {
                buffer = 0;
                count_of_chunks ++;
            }
        }

        if(buffer == chunk_sum)
            count_of_chunks++;
        
        return count_of_chunks == 3;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> data = {
        0,2,1,-6,6,-7,9,1,2,0,1
        // 0,2,1,-6,6,7,9,-1,2,0,1
        // 3,3,6,5,-2,2,5,1,-9,4
    };
    auto result = s.canThreePartsEqualSum(data);
    std::cout << std::boolalpha << "Result: " << result << std::endl;
    return 0;
}
