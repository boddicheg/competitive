#include <iostream>
#include <vector>
#include <stack>
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
    std::string removeDuplicates(std::string S)
    {
        std::string st;

        for (auto &&i : S)
        {
            if (st.empty() || st.back() != i)
                st.push_back(i);
            else
                st.pop_back();
        }
        return st;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.removeDuplicates("abbaca");
    auto result = s.removeDuplicates("aaaaaaaaaa");
    std::cout << "Result: " << result << std::endl;
    return 0;
}
