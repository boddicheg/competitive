#include <iostream>
#include <vector>
#include <sstream>
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
    int lengthOfLastWord(string s)
    {
        std::stringstream ss(s);
        std::string buffer;
        std::string result;
        while(std::getline(ss, buffer, ' '))
        {
            if(buffer.size() > 0)
                result = buffer;
        }
        return result.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::cout << s.lengthOfLastWord("Hello dsfdf  swef ds sdfdf Wodddrld     ") << std::endl;
    return 0;
}
