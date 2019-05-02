#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Solution
{
public:
    int sum = 0;

    void reverse_inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->right != nullptr) reverse_inorder(root->right);
        root->val = (sum += root->val);
        if (root->left != nullptr) reverse_inorder(root->left);
    }

    TreeNode *convertBST(TreeNode *root)
    {
        reverse_inorder(root);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(5);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(13);
    print(t1);

    Solution s;
    TreeNode *r = s.convertBST(t1);
    print(r);

    delete t1->right;
    delete t1->left;
    delete t1;
    return 0;
}
