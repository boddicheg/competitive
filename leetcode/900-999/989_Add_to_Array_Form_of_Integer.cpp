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

class Solution {
public:
    std::vector<int> addToArrayForm(const std::vector<int>& A, int K)
    {
        std::vector<int> result(A);

        int left = 0;
        int i = result.size() - 1;
        while (K > 0)
        {
            int digit = K % 10;

            int sum = 0;
            if (i >= 0)
            {
                sum = result.at(i) + digit + left;
                if (sum > 9)
                {
                    left = sum / 10;
                    result.at(i) = sum % 10;
                }
                else
                {
                    result.at(i) = sum;
                    left = 0;
                }
            }
            else
            {
                sum = 0 + digit + left;
                if (sum > 9)
                {
                    left = sum / 10;
                    result.insert(result.begin(), sum % 10);
                }
                else
                {
                    result.insert(result.begin(), sum);
                    left = 0;
                }
            }

            i--;
            K /= 10;
        }

        for (int j = i; j >= 0 ; j--)
        {
            int sum = result.at(j) + left;
            if (sum > 9)
            {
                left = sum / 10;
                result.at(j) = sum % 10;
            }
            else
            {
                result.at(j) = sum;
                left = 0;
            }
        }

        if (left != 0)
        {
            result.insert(result.begin(), left);
        }

        return result;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    auto result = s.addToArrayForm({1,2,0,0}, 34);
    auto result1 = s.addToArrayForm({1}, 33);
    auto result2 = s.addToArrayForm({2,1,5}, 806);
    auto result3 = s.addToArrayForm({9,9,9,9,9,9,9,9,9,9}, 1);
    auto result4 = s.addToArrayForm({0}, 10000);
    std::cout << "Result: " << result << std::endl;
    std::cout << "Result: " << result1 << std::endl;
    std::cout << "Result: " << result2 << std::endl;
    std::cout << "Result: " << result3 << std::endl;
    std::cout << "Result: " << result4 << std::endl;
    return 0;
}
