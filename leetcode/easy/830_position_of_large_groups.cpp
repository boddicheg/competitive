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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        vector<vector<int>> result;
        std::string current_streak;
        int left_pos = -1, right_pos = -1;
        char previos = 0;
        for (size_t i = 0; i < S.size(); i++)
        {
            char current = S.at(i);
            if (i == 0)
            {
                left_pos = i;
                right_pos = i;
            }
            else
            {
                // std::cout << previos << " -> " << current << " [" << left_pos << ", " << right_pos << "]" << std::endl;
                if (current == previos)
                    right_pos ++;
                else
                {
                    if ((right_pos - left_pos) + 1 >= 3)
                    {
                        result.push_back({left_pos, right_pos});
                    }
                    left_pos = i;
                    right_pos = i;
                }
            }
            previos = S.at(i);
        }
        if ((right_pos - left_pos) + 1 >= 3)
        {
            result.push_back({left_pos, right_pos});
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.largeGroupPositions("abbxxxxzzy");
    // auto result = s.largeGroupPositions("abc");
    auto result = s.largeGroupPositions("abcdddeeeeaabbbcd");
    for (const auto &e : result)
        print(e);
    return 0;
}
