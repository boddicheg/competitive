#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        std::queue<std::pair<int, int>> q;
        std::vector<std::pair<int, int>> visited;
        q.push(std::make_pair(sr, sc));

        int main_color = image.at(sr).at(sc);

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(std::find_if(visited.begin(), visited.end(), [=](const std::pair<int, int>& p) {
                return p.first == x && p.second == y;
            }) != visited.end())
            {
                continue;
            }
            visited.push_back(std::make_pair(x, y));
            image.at(x).at(y) = newColor;
            if((y - 1) >= 0  && image.at(x).at(y - 1) == main_color)
                q.push(std::make_pair(x, y - 1));
            if((y + 1) < image.at(0).size() && image.at(x).at(y + 1) == main_color)
                q.push(std::make_pair(x, y + 1));
            if((x - 1) >= 0  && image.at(x -1).at(y) == main_color)
                q.push(std::make_pair(x - 1, y));
            if((x + 1) < image.size() && image.at(x + 1).at(y) == main_color)
                q.push(std::make_pair(x + 1, y));
        }

        return image;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> image =
    {
        {1, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 1}
    };
    // vector<vector<int>> image =
    // {
    //     {0, 0, 0},
    //     {0, 1, 1},
    // };
    Solution s;
    auto result = s.floodFill(image, 1, 1, 2);
    for (const auto &e : result)
        print(e);
    return 0;
}
