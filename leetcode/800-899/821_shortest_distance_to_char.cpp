#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

std::vector<int> shortestToChar(std::string S, char C)
{
    std::vector<int> result(S.size(), 9999999);
    size_t latest_index = 0;
    while (true)
    {
        size_t position = S.find_first_of(C, latest_index);
        if (position != std::string::npos)
        {
            result.at(position) = 0;
            int left_border = position, right_border = position;
            int left_path = 0, right_path = 0;
            // left direction
            while (left_border >= 0)
            {
                // std::cout << "Update left" << std::endl;
                if (S.at(left_border) == C && left_border != position) break;
                if (result.at(left_border) > left_path)
                    result.at(left_border) = ++left_path;
                left_border--;
            }
            // right direction
            while (right_border < S.size())
            {
                // std::cout << "Update right" << std::endl;
                if (S.at(right_border) == C && right_border != position) break;
                if (result.at(right_border) > right_path)
                    result.at(right_border) = ++right_path;

                right_border++;
            }
            latest_index = position + 1;
        }
        else
            break;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    auto result = shortestToChar("loveleetcode", 'e');
    for (const auto &val : result)
        std::cout << val << " ";
    std::cout << std::endl;

    return 0;
}