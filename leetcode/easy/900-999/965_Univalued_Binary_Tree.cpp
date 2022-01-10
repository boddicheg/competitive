#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bst.hpp>
using namespace structures;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        int root_val = root->val;

        std::queue<TreeNode *> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode * top = q.front();
            q.pop();

            if (top == nullptr)
                continue;

            if (top->val != root_val)
                return false;

            q.push(top->left);
            q.push(top->right);
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(10);
    root->right = new TreeNode(11);
    std::cout << std::boolalpha << s.isUnivalTree(root) << std::endl;
    remove(root);
    return 0;
}
