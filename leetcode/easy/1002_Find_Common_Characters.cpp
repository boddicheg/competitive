#include <iostream>
#include <vector>
#include <map>
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
    std::vector<std::string> commonChars(std::vector<std::string> &A)
    {
        std::vector<int> frequency(26, std::numeric_limits<int>::max());

        for (size_t i = 0; i < A.size(); i++)
        {
            std::vector<int> str_frequency(26, 0);
            for (size_t j = 0; j < A.at(i).size(); j++)
                str_frequency[A.at(i).at(j) - 'a']++;

            for (size_t j = 0; j < 26; j++)
                frequency.at(j) = std::min(frequency.at(j), str_frequency.at(j));
        }

        std::vector<std::string> result;
        for (size_t i = 0; i < 26; i++)
        {
            for (size_t j = 0; j < frequency.at(i); j++)
                result.push_back(std::string(1, i + 'a'));
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::string> data = {"bella", "label", "roller"};
    auto result = s.commonChars(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
