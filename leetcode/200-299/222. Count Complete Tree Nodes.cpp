/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    int treeHeightLeft(TreeNode* root) {
        int h;
        while (root)
        {
            h++;
            root = root->left;
        }
        return h;
    }
    int treeHeightRight(TreeNode* root) {
        int h;
        while (root)
        {
            h++;
            root = root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = treeHeightLeft(root);
        int rh = treeHeightRight(root);

        if (lh == rh) return (1 << lh) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};