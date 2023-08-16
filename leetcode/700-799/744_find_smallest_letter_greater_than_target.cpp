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
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (const auto &l : letters)
        {
            if (l > target)
                return l;
        }
        // end of
        return letters.at(0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<char> v1 = {'c', 'f', 'j'};
    std::cout << s.nextGreatestLetter(v1, 'j') << std::endl;
    return 0;
}
