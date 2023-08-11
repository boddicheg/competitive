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
    int min = std::numeric_limits<int>::max();
    int previous = std::numeric_limits<int>::min();

    void _getMinimumDifference(TreeNode* root)
    {
        if(root == nullptr)
            return;

        if (root->right != nullptr) _getMinimumDifference(root->right);
        if(previous == std::numeric_limits<int>::min())
            previous = root->val;
        else
        {
            min = std::min(std::abs(previous - root->val), min);
            previous = root->val;
        }
        if (root->left != nullptr) _getMinimumDifference(root->left);
    }

    int getMinimumDifference(TreeNode* root)
    {
        _getMinimumDifference(root);
        return min;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(4);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(13);
    print(t1);

    Solution s;
    std::cout << s.getMinimumDifference(t1) << std::endl;

    delete t1->right;
    delete t1->left;
    delete t1;
    return 0;
}
