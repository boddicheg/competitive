#include <iostream>
#include <queue>
#include <vector>
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

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
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

class Solution
{
public:
    bool isContains(TreeNode *t1, TreeNode *t2)
    {

        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (t1 == nullptr || t2 == nullptr)
            return false;

        return t1->val == t2->val && isContains(t1->left, t2->left) && isContains(t1->right, t2->right);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr)
            return false;

        return isContains(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(1);
    // t1->right = new TreeNode(5);
    // t1->left->left = new TreeNode(1);
    // t1->left->right = new TreeNode(2);
    // t1->left->right->left = new TreeNode(0);
    // print(t1);

    TreeNode *t2 = new TreeNode(1);
    // t2->left = new TreeNode(1);
    // t2->right = new TreeNode(2);
    // print(t2);

    Solution s;
    std::cout << std::boolalpha << s.isSubtree(t1, t2) << std::endl;

    // delete t1->left->left;
    // delete t1->left->right;
    // delete t1->right;
    // delete t1->left;
    // delete t1;

    // delete t2->right;
    // delete t2->left;
    // delete t2;

    return 0;
}