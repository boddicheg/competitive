#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bst.hpp>
using namespace structures;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

// Definition for a binary tree node.

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

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        if (root == nullptr)
            return 0;
        return ((root->val >= L && root->val <= R) ? root->val : 0) + 
               ((root->val > L) ? rangeSumBST(root->left, L, R) : 0) + 
               ((root->val < R) ? rangeSumBST(root->right, L, R) : 0);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    // auto result = s.template(..);
    // std::cout << "Result: " << result << std::endl;
    TreeNode* root = new TreeNode(15);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    // TreeNode* root = create({ 5, 4, 6 });
    // std::cout << root << std::endl;
    std::cout << s.rangeSumBST(root, 1, 10) << std::endl;
    remove(root);
    return 0;
}
