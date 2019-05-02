#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    string tree2str(TreeNode *t)
    {
        std::string result;
        if (t == nullptr)
            return result;

        result += std::to_string(t->val);
        if (t->left != nullptr)
        {
            result += "(";
            result += tree2str(t->left);
            result += ")";
        }
        else if (t->right != nullptr)
            result += "()";

        if (t->right != nullptr)
        {
            result += "(";
            result += tree2str(t->right);
            result += ")";
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    print(t1);

    std::cout << s.tree2str(t1) << std::endl;

    delete t1->left;
    delete t1->right;
    delete t1;

    return 0;
}
