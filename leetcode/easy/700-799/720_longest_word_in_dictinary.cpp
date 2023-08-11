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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
// slow
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        std::string result;
        std::unordered_set<std::string> table{words.begin(), words.end()};

        for (const auto &e : words)
        {
            std::string w = e;
            while (!w.empty() && table.count(w) > 0)
                w.pop_back();

            if (w.empty() && (result.size() < e.size() || (result.size() == e.size() && e < result)))
                result = e;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<std::string> data = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    // std::vector<std::string> data = {"w", "wo", "wor", "worl", "world"};
    std::vector<std::string> data = {"m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat"};
    std::cout << s.longestWord(data) << std::endl;
    return 0;
}
