#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void delete_tree(TreeNode * node)
{
    if (node->left != nullptr)
    {
        TreeNode * left = node->left;
        node->left = nullptr;
        delete_tree(left);
    }
    if (node->right != nullptr)
    {
        TreeNode * right = node->right;
        node->right = nullptr;
        delete_tree(right);
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
        node = nullptr;
    }
}

std::string to_string(TreeNode *root)
{
    if (root == nullptr)
        return "[]";

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void print(TreeNode *root)
{
    std::cout << to_string(root) << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int depth(TreeNode* root, bool& b)
    {
        if (root == nullptr)
            return true;

        int dl = depth(root->left, b) + 1;
        int dr = depth(root->right, b) + 1;

        if (std::abs(dl - dr) > 1)
            b = false;

        return std::max(dl, dr);
    }

    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        bool balanced = true;
        depth(root, balanced);
        return balanced;
    }
};

int main(int argc, char const *argv[])
{
    // TreeNode *t1 = new TreeNode(3);
    // t1->left = new TreeNode(9);
    // t1->right = new TreeNode(20);
    // t1->right->left = new TreeNode(15);
    // t1->right->right = new TreeNode(7);

    TreeNode *t1 = new TreeNode(1);
    t1->right = new TreeNode(2);
    t1->left = new TreeNode(2);
    t1->left->right = new TreeNode(3);
    t1->left->left = new TreeNode(3);
    t1->left->left->right = new TreeNode(4);
    t1->left->left->left = new TreeNode(4);
    print(t1);

    Solution s;
    int result = s.isBalanced(t1);
    std::cout << result << std::endl;

    delete_tree(t1);

    return 0;
}