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

    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        int ax = rec1.at(0);
        int ay = rec1.at(1);

        int bx = rec1.at(2);
        int by = rec1.at(3);

        int ex = rec2.at(0);
        int ey = rec2.at(1);

        int fx = rec2.at(2);
        int fy = rec2.at(3);

        if(ax >= fx || ex >= bx)
            return false;

        if(by <= ey || fy <= ay)
            return false;

        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> rec1 = {7,8,13,15};
    std::vector<int> rec2 = {10,8,12,20};

    // std::vector<int> rec1 = {0,0,2,2};
    // std::vector<int> rec2 = {1,1,3,3};

    // std::vector<int> rec1 = {0,0,1,1};
    // std::vector<int> rec2 = {1,0,2,1};

    std::cout << std::boolalpha << s.isRectangleOverlap(rec1, rec2) << std::endl;
    return 0;
}
