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

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:

    Node* build(vector<vector<int>> &grid, int x, int y, int size)
    {
        // exit
        if (size == 1)
            // return leaf
            return new Node(grid.at(x).at(y) == 1, true, nullptr, nullptr, nullptr, nullptr);

        size /= 2;

        Node* topLeft = build(grid, x, y, size);
        Node* topRight = build(grid, x, y + size, size);
        Node* bottomLeft = build(grid, x + size, y, size);
        Node* bottomRight = build(grid, x + size, y + size, size);

        bool all_leaves = topRight->isLeaf && topLeft->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf;
        bool all_have_true = topLeft->val && topRight->val && bottomLeft->val && bottomRight->val;
        bool all_have_false = topLeft->val || topRight->val || bottomLeft->val || bottomRight->val;

        if(all_leaves && (all_have_true || !all_have_false))
        {
            int tmp = topLeft->val;
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return new Node(tmp, true, nullptr, nullptr, nullptr, nullptr);
        }

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node *construct(vector<vector<int>> &grid)
    {
        int N = grid.size();
        if (N == 0)
            return nullptr;
        return build(grid, 0, 0, N);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
