#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <bst.hpp>
using namespace structures;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();

class Solution {
public:
    void travestal(TreeNode* root, int num)
    {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr)
        {
            num = 2 * num + root->val;
            sum += num;
            return;
        }

        num = 2 * num + root->val;

        travestal(root->left, num);
        travestal(root->right, num);
        return;
    }

    int sumRootToLeaf(TreeNode* root)
    {
        travestal(root, 0);
        return sum;
    }
private:
    int sum = 0;
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    auto result = s.sumRootToLeaf(root);
    std::cout << "Result: " << result << std::endl;

    remove(root);
    return 0;
}
