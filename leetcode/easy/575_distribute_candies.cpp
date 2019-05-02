#include <iostream>
#include <set>
#include <vector>
using namespace std;

int distributeCandies(vector<int> &candies)
{
    std::set<int> kinds;
    for (const auto &candy : candies)
        kinds.insert(candy);

    return std::min(kinds.size(), candies.size() / 2);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> data =
    {
        {1, 1, 2, 2, 3, 3},
        {1, 1, 2, 3},
        {1, 1, 1, 1, 2, 2, 2, 3, 3, 3},
        {0, 0, 14, 0, 10, 0, 0, 0},
        {1000, 1000, 2, 1, 2, 5, 3, 1}
    };

    for (auto &subset : data)
    {
        int result = distributeCandies(subset);
        std::cout << result << std::endl;
    }

    return 0;
}