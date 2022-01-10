#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

int arrayPairSum(vector<int> &nums)
{
    size_t n = nums.size() / 2;
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (i % 2 == 0) sum += nums.at(i);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    auto data = vector<int>({1, 4, 3, 2});
    int sum = arrayPairSum(data);
    cout << sum << endl;
    return 0;
}