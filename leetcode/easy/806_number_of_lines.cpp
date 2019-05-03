#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

vector<int> numberOfLines(vector<int> &widths, string S)
{
    int count = 1;
    int line_size = 0;

    for (const auto &letter : S)
    {
        int w = widths.at((int)letter - 97);
        if (line_size + w > 100)
        {
            count++;
            line_size = w;
        }
        else
            line_size += w;
    }

    return { count,  line_size };
}

int main(int argc, char const *argv[])
{
    // vector<int> widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    // std::string S = "abcdefghijklmnopqrstuvwxyz";
    // vector<int> widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    // std::string S = "bbbcccdddaaa";
    vector<int> widths = {5, 7, 4, 7, 6, 7, 9, 5, 8, 8, 5, 10, 9, 10, 2, 5, 7, 9, 3, 8, 8, 8, 10, 2, 2, 9};
    std::string S = "lgrnv";

    auto result = numberOfLines(widths, S);
    std::cout << result.at(0) << " " << result.at(1) << std::endl;
    return 0;
}