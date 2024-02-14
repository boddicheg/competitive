#include <iostream>
#include <vector>
#include <set>
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

class Solution
{
public:
    void swapLeaf(TreeNode* root)
    {
        if (root == nullptr)
            return;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        swapLeaf(root->left);
        swapLeaf(root->right);
    }

    TreeNode* invertTree(TreeNode* root)
    {
        swapLeaf(root);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
