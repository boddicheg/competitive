#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> result;
        int middle = std::sqrt(area);
        for (int i = middle; i > 0; --i)
        {
            if ((area % i) == 0)
            {
                int second = area / i;
                if (second * i == area)
                {
                    result.push_back(std::max(i, second));
                    result.push_back(std::min(i, second));
                    break;
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.constructRectangle(4);
    s.constructRectangle(10000000);
    return 0;
}
