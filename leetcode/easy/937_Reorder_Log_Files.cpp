#include <iostream>
#include <vector>
#include <unordered_map>
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
    std::vector<std::string> reorderLogFiles(std::vector<std::string> &logs)
    {
        struct LogCache
        {
            bool is_letter;
            bool is_digit;
            int idx;
            std::string id;
            std::string rest;
        };

        std::unordered_map<std::string, LogCache> cache;

        for (auto &&line : logs)
        {
            LogCache l;
            l.idx = line.find_first_of(' ');
            l.id = std::string(line.begin(), line.begin() + l.idx);
            l.rest = std::string(line.begin() + l.idx + 1, line.end());
            l.is_letter = std::isalpha(line.at(l.idx + 1));
            l.is_digit = std::isdigit(line.at(l.idx + 1));
            cache[line] = std::move(l);
        }
        
        std::stable_sort(logs.begin(), logs.end(), [&cache](const std::string &a, const std::string &b) {

            LogCache& l1 = cache.at(a);
            LogCache& l2 = cache.at(b);

            if (l1.is_letter && l2.is_letter)
            {
                return l1.rest + l1.id < l2.rest + l2.id;
            }
            else if (l1.is_letter && l2.is_digit)
            {
                return true;
            }
            else if (l1.is_digit && l2.is_letter)
            {
                return false;
            }

            return false;
        });
        return logs;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::string> data = {
        // "a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo"
        "t kvr", "r 3 1", "i 403", "7 so", "t 54"    
    };

    auto result = s.reorderLogFiles(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
