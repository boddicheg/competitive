#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template <typename T>
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

std::ostream &operator<<(std::ostream &ss, const std::vector<int> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    std::pair<size_t, size_t> get_pawn_idx(std::vector<std::vector<char>> &board, size_t x, size_t y, int dirx, int diry)
    {
        std::pair<size_t, size_t> result = {-1, -1};
        size_t new_x = x;
        size_t new_y = y;
        while (true)
        {
            new_x += dirx;
            new_y += diry;

            if (new_x < 0 || new_x >= board.size())
                break;
            if (new_y < 0 || new_y >= board.at(0).size())
                break;
            char cell = board.at(new_y).at(new_x);
            if (cell == '.')
                continue;
            else if (std::isupper(cell))
                return {-1, -1};
            else
                return {new_x, new_y};
        }
        return result;
    }

    int numRookCaptures(std::vector<std::vector<char>> &board)
    {
        // Check rook idxes
        size_t x_idx = 0;
        size_t y_idx = 0;

        for (size_t i = 0; i < board.size(); i++)
        {
            for (size_t j = 0; j < board.at(i).size(); j++)
            {
                if (board.at(i).at(j) == 'R')
                {
                    y_idx = i;
                    x_idx = j;
                }
            }
        }
        std::cout << "[" << x_idx << ", " << y_idx << "]" << std::endl;
        int result = 0;

        auto pos = get_pawn_idx(board, x_idx, y_idx, 1, 0);
        if (pos.first != -1 || pos.second != -1)
            result++;

        pos = get_pawn_idx(board, x_idx, y_idx, -1, 0);
        if (pos.first != -1 || pos.second != -1)
            result++;

        pos = get_pawn_idx(board, x_idx, y_idx, 0, -1);
        if (pos.first != -1 || pos.second != -1)
            result++;

        pos = get_pawn_idx(board, x_idx, y_idx, 0, 1);
        if (pos.first != -1 || pos.second != -1)
            result++;

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<std::vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'R', '.', '.', '.', 'B'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    auto result = s.numRookCaptures(board);
    std::cout << "Result: " << result << std::endl;
    return 0;
}
