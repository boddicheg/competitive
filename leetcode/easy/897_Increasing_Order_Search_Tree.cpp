#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bst.hpp>
using namespace structures;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

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

template <typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution
{
public:
    TreeNode *rotateNonClockwise(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;

        if (root->left != nullptr && root->right == nullptr)
            return root;

        TreeNode *temp = root->right;
        root->right = nullptr;
        TreeNode *temp2 = temp;
        while (temp2->left != nullptr)
            temp2 = temp2->left;
        temp2->left = root;

        root = temp;
        return root;
    }

    TreeNode *rotateClockwise(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        if (root->left == nullptr && root->right == nullptr)
            return root;

        if (root->left == nullptr && root->right != nullptr)
            return root;

        TreeNode *temp = root->left;
        root->left = nullptr;
        TreeNode *temp2 = temp;
        while (temp2->right != nullptr)
            temp2 = temp2->right;
        temp2->right = root;
        root = temp;
        return root;
    }

    TreeNode *rotateLeftSubTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        if (root->left != nullptr)
            root->left = rotateLeftSubTree(root->left);
        if (root->right != nullptr)
            root->right = rotateLeftSubTree(root->right);

        root = rotateNonClockwise(root);

        return root;
    }

    TreeNode *rotateRightSubTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        if (root->left != nullptr)
            root->left = rotateRightSubTree(root->left);
        if (root->right != nullptr)
            root->right = rotateRightSubTree(root->right);

        root = rotateClockwise(root);

        return root;
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;

        root->left = rotateLeftSubTree(root->left);
        root->right = rotateRightSubTree(root->right);

        while (root->left != nullptr)
        {
            TreeNode *node = root->left;
            root->left = nullptr;
            node->right = root;
            root = node;
        }
        return root;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    // Example 1
    // TreeNode * root = new TreeNode(5);
    // root->left = new TreeNode(3);
    // root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(4);
    // root->left->left->left = new TreeNode(1);

    // root->right = new TreeNode(6);
    // root->right->right = new TreeNode(8);
    // root->right->right->left = new TreeNode(7);
    // root->right->right->right = new TreeNode(9);

    // Example 2
    // TreeNode * root = new TreeNode(4);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(1);
    // root->left->right = new TreeNode(3);

    // Example 3
    TreeNode *root = new TreeNode(54);
    root->right = new TreeNode(57);
    root->right->left = new TreeNode(788);
    root->right->left->right = new TreeNode(876);

    std::cout << "[" << root << "]" << std::endl;
    auto result = s.increasingBST(root);
    std::cout << "Result: [" << result << "]" << std::endl;

    remove(root);
    return 0;
}
