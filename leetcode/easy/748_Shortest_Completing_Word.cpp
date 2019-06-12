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
    std::string shortestCompletingWord(std::string licensePlate, std::vector<std::string> &words)
    {
        std::map<char, int> lic;
        for (auto &&c : licensePlate)
            if (isalpha(c))
                lic[std::tolower(c)]++;

        int smallest = std::numeric_limits<int>::max();
        std::string result;
        for (auto &&word : words)
        {
            bool fit = true;
            for (auto &&p : lic)
            {
                int count = std::count(word.begin(), word.end(), p.first);
                if (count < p.second)
                {
                    fit = false;
                    break;
                }
            }

            if (fit)
            {
                if(word.size() < smallest)
                {
                    smallest = word.size();
                    result = word;
                }
            }   
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::string lic = "1s3 PSt";
    // std::vector<std::string> words = {"step", "steps", "stripe", "stepple"};
    std::string lic = "1s3 456";
    std::vector<std::string> words = {"looks", "pest", "stew", "show"};

    auto result = s.shortestCompletingWord(lic, words);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
