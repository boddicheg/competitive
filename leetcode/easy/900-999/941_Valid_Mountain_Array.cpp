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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if (arr.size() < 3)
            return false;

        int prev = 0;
        int curr = 0;
        int i = 1; 
        int c_climb = 0;
        int c_fall = 0;
        do 
        {
            prev = arr.at(i - 1);
            curr = arr.at(i);
            i++;
            if (prev < curr)
                c_climb++;
        } while(prev < curr && i < arr.size());

        if (prev == curr || c_climb == 0)
            return false;

        while(prev > curr) 
        {
            if (prev > curr)
                c_fall++;
            if (i == arr.size())
                break;
            prev = arr.at(i - 1);
            curr = arr.at(i);
            i++;
        }

        if (prev <= curr || c_fall == 0)
            return false;

        return i == arr.size() ;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // vector<int> v {2,0,2};
    vector<int> v {0,3,2,1};
    // vector<int> v {0,1,2,1,2};
    auto result = s.validMountainArray(v);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
