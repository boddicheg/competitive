#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void delete_tree(TreeNode * node)
{
    if (node->left != nullptr)
    {
        TreeNode * left = node->left;
        node->left = nullptr;
        delete_tree(left);
    }
    if (node->right != nullptr)
    {
        TreeNode * right = node->right;
        node->right = nullptr;
        delete_tree(right);
    }

    if (node->left == nullptr && node->right == nullptr)
    {
        delete node;
        node = nullptr;
    }
}

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

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    int curr = -99999999;
    std::size_t curr_count = 0;
    std::size_t max_count = 0;

    vector<int> res;

    vector<int> findMode(TreeNode* root) {
        if (!root)
            return res;
        inorder(root);
        // std::cout << std::endl << "MAX: " << max_count << std::endl;
        // curr = -99999999;
        // curr_count = 0;
        // inorder(root, max_count);

        return res;
    }

    void inorder(TreeNode* root)
    {
        if (!root)
            return;
        
        inorder(root->left);
        //--------------------------------------
        if (curr == root->val)
        {
            curr_count++;
        }
        else
        {
            curr_count = 1;
            curr = root->val;
        }

        // only on second pass
        if (curr_count == max_count)
            res.push_back(curr);
        else if (curr_count > max_count)
        {
            max_count = curr_count;
            res.assign(1, curr);
        }
        //--------------------------------------
        inorder(root->right);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    t1->right = new TreeNode(2);
    t1->right->left = new TreeNode(2);
    // t1->right->left->right = new TreeNode(3);
    print(t1);

    Solution s;
    auto result = s.findMode(t1);
    std::cout << result << std::endl;

    delete_tree(t1);
    return 0;
}