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
    std::vector<int> sumEvenAfterQueries(std::vector<int> &A, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> even;
        int sum = 0;

        for (auto &&j : A)
        {
            if (j % 2 == 0)
                sum += j;
        }
        // even.push_back(sum);

        for (auto &&i : queries)
        {
            int val = i.at(0);
            int idx = i.at(1);

            int current = A.at(idx);
            bool its_even_now = current % 2 == 0;
            bool its_even_after_sum = (current + val) % 2 == 0;

            if (its_even_now && its_even_after_sum)
                sum += val;
            else if (its_even_now && !its_even_after_sum)
                sum -= current;
            else if (!its_even_now && its_even_after_sum)
                sum += val + current;

            A.at(idx) += val;
            even.push_back(sum);
        }
        
        return even;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> A = {1, 2, 3, 4};
    std::vector<std::vector<int>> q = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
    auto result = s.sumEvenAfterQueries(A, q);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
