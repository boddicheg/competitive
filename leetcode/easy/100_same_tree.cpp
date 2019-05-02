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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
            return false;
        if (p == nullptr && q == nullptr)
            return true;

        if (p->val != q->val)
            return false;
        else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(4);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    print(t1);

    TreeNode *t2 = new TreeNode(3);
    t2->left = new TreeNode(4);
    t2->right = new TreeNode(20);
    t2->right->left = new TreeNode(15);
    // t2->right->right = new TreeNode(7);
    print(t2);

    Solution s;
    std::cout << std::boolalpha << s.isSameTree(t1, t2) << std::endl;

    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;
    return 0;
}
