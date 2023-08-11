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

// 1. Brute force 
class Solution0 {
public:
    int sumOddLengthSubarrays(const std::vector<int>& arr)
    {
        int result = 0;

        int idx = 0;
        int window = 1;
        while(true)
        {
            for (size_t i = idx; i < arr.size(); i++)
            {
                if (i + window > arr.size())
                    break;
                for (size_t j = 0; j < window; j++)
                {
                    result += arr.at(j + i);
                }
            }

            if (window >= arr.size())
                break;
            
            window += 2;
            idx = 0;
        }
    
        return result;
    }
};

// 2. 0(n)
/*

1
4
2
5
3
1 4
4 2
2 5
5 3
1 4 2
4 2 5
2 5 3
1 4 2 5
4 2 5 3
1 4 2 5 3

Sum of all subarrays
N = 5
idx   a[i]   Total
0   -  1   -   5  -> 1 * 5
1   -  4   -   8  -> 2 * 4
2   -  2   -   9  -> 3 * 3
3   -  5   -   8  -> 4 * 2
4   -  3   -   5  -> 5 * 1

SO:  (idx + 1) * (N - idx)
Divide by 2 for odd: ((idx + 1) * (N - idx) + 1) / 2
Divide by 2 for even: ((idx + 1) * (N - idx)) / 2
Cheking:
                                count * a[i]
((0 + 1) * (5 - 0) + 1) / 2 ->  3 * 1 -> 3
((1 + 1) * (5 - 1)) / 2 ->  4 * 4 -> 16
((2 + 1) * (5 - 2) + 1) / 2 ->  5 * 2 -> 10
((3 + 1) * (5 - 3)) / 2 ->  4 * 5 -> 20
((4 + 1) * (5 - 4) + 1) / 2 ->  3 * 3 -> 9
*/
class Solution {
public:
    int sumOddLengthSubarrays(const std::vector<int>& arr)
    {
        int result = 0;
        int N = arr.size();
        for (size_t i = 0; i < N; i++)
            result += ((i + 1) * (N - i) + ((i % 2 == 0) ? 1 : 0)) / 2 * arr.at(i);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.sumOddLengthSubarrays({1,4,2,5,3});
    std::cout << "Result: " << result << std::endl;
    auto result1 = s.sumOddLengthSubarrays({1,2});
    std::cout << "Result: " << result1 << std::endl;
    auto result2 = s.sumOddLengthSubarrays({10,11,12});
    std::cout << "Result: " << result2 << std::endl;
    return 0;
}
