#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(const vector<vector<int>>& A)
    {
        vector<vector<int>> result;
        for(auto subvec: A)
        {
            vector<int> resulted;
            std::transform(subvec.rbegin(), subvec.rend(), std::back_inserter(resulted), [] (int n) { return (n) ? 0 : 1; });
            result.push_back(resulted);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.flipAndInvertImage({{1, 1, 0}, { 1, 0, 1 }, { 0, 0, 0 }});
    return 0;
}
