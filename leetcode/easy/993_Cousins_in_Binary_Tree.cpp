#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bst.hpp>
using namespace structures;

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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
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

    struct Node
    {
        int target = -1;
        int parent = -1;
        int depth = -1;
    };

    std::vector<Node> matches;

    void travestal(TreeNode *root, int x, int y, int parent, int depth)
    {
        if (root == nullptr)
            return;

        if (root->val == x || root->val == y)
        {
            matches.push_back( { root->val, parent, depth } );
        }
        travestal(root->left, x, y, root->val, depth + 1);
        travestal(root->right, x, y, root->val, depth + 1);
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        travestal(root, x, y, -1, 0);
        return matches.at(0).depth == matches.at(1).depth && 
                matches.at(0).parent != matches.at(1).parent;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);

    // int x = 4;
    // int y = 3;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);

    int x = 2;
    int y = 4;


    auto result = s.isCousins(root, x, y);

    std::cout << "Result: " << result << std::endl;
    remove(root);
    return 0;
}
