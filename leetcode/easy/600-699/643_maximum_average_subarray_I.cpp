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

// SLOW!
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = 0;
        for (int j = 0; j < k; ++j)
            sum += nums.at(j);
        int result = sum;

        for (int i = k; i < nums.size(); ++i)
        {
            sum += nums.at(i) - nums.at(i - k);
            result = std::max(result, sum);
        }

        return result / (double)k;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // std::vector<int> data = {1, 12, -5, -6, 50, 3};
    std::vector<int> data = {9672,-6795,2696,-97,6315,936,4482,5863,5046,-1376,-4328,-7112,-7844,-3295,5268,5029,-2665,-8250,-879,8716,4184,-6046,-366,-1785,875,4281,-3168,2248,7773,-5652,2100,2575,432,4523,-9309,-9232,-59,-1532,-1493,-9329,-1850,7945,-1224,-2646,-8007,-6395,-396,9638,5254,-2544,-4907,3706,6002,-9347,6248,-47,-9564,4105,-4256,-1794,6345,-780,-3363,-5389,-8173,4810,6787,3589,-850,-9937,-6255,4218,-6299,-9022,-152,1063,-2003,-3677,9704,-6182,-9562,5489,6350,-1083,-7537,-3583,3029};
    // std::vector<int> data = { -1};
    // std::cout << s.findMaxAverage(data, 1) << std::endl;
    // std::cout << s.findMaxAverage(data, 4) << std::endl;
    std::cout << s.findMaxAverage(data, 31) << std::endl;
    return 0;
}
