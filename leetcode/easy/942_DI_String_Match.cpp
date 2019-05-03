#include <iostream>
#include <vector>
#include <set>
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

class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        vector<int> result;
        int right = S.size();
        int left = 0;
        for (size_t i = 0; i < S.size(); i++)
        {
            if (S.at(i) == 'I')
                result.push_back(left++);
            else
                result.push_back(right--);
        }
        result.push_back(left);

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.diStringMatch("IDID");
    // auto result = s.diStringMatch("III");
    auto result = s.diStringMatch("DDI");
    for (const auto &e : result)
        std::cout << e << " ";
    std::cout << std::endl;
    return 0;
}
