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
class Solution {
public:
    void mergeNode(TreeNode* t1, TreeNode* t2)
    {
        if(t1 != nullptr && t2 != nullptr)
        {
            t1->val += t2->val;

            if(t1->left != nullptr && t2->left != nullptr)
                mergeNode(t1->left, t2->left);
            else if(t1->left == nullptr && t2->left != nullptr)
                t1->left = t2->left;

            if(t1->right != nullptr && t2->right != nullptr)
                mergeNode(t1->right, t2->right);
            else if(t1->right == nullptr && t2->right != nullptr)
                t1->right = t2->right;
        }
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        TreeNode* result = t1;
        mergeNode(result, t2);
        return result;
    }
};