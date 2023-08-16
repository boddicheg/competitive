#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:
    void inorder(TreeNode* root)
    {
        if (root == nullptr)
            return;
        
        inorder(root->left);
        r.push_back(root->val);
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return r;
    }

private:
    vector<int> r;
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return {};

        std::stack<TreeNode*> s;
        std::vector<int> r;

        TreeNode* current = root;

        while (current != nullptr || !s.empty())
        {
            // LEFT
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            // ROOT
            current = s.top();
            s.pop();

            r.push_back(current->val);
            // RIGHT
            current = current->right;
        }
        return r;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    print(t1);

    Solution s;
    auto result = s.inorderTraversal(t1);
    std::cout << result << std::endl;

    delete_tree(t1);
    return 0;
}