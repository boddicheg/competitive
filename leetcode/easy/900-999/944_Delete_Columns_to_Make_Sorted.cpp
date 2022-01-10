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
    int minDeletionSize(vector<string> &A)
    {
        int D = 0;

        for (size_t i = 0; i < A.at(0).size(); ++i)
        {
            for (size_t j = 0; j < A.size() - 1; ++ j)
            {
                if (A.at(j).at(i) > A.at(j + 1).at(i))
                {
                    D++;
                    break;
                }
            }
        }
        return D;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> data({"cba", "daf", "ghi"});
    // vector<string> data({"zyx", "wvu", "tsr"});
    auto result = s.minDeletionSize(data);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
