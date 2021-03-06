#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

class Solution
{
public:
    int levels(TreeNode *root, int lvl)
    {
        if (root == nullptr)
            return 0;
        int left = levels(root->left, lvl + 1);
        int right = levels(root->right, lvl + 1);
        max = std::max(max, left + right + 1);
        return std::max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        max = 1;
        levels(root, 0);
        return max - 1;
    }
private:
    int max = 0;
};

int main(int argc, char const *argv[])
{
    Solution s;

    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    t1->right->right->right = new TreeNode(7);
    t1->right->right->left = new TreeNode(7);
    t1->right->right->left->left = new TreeNode(7);
    print(t1);

    std::cout << s.diameterOfBinaryTree(t1) << std::endl;
    return 0;
}
