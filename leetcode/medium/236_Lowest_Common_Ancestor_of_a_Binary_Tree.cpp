#include <iostream>
#include <queue>
#include <set>
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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution {
public:

    bool dfs(TreeNode* root, TreeNode* p, vector<TreeNode*>& v)
    {
        if (root == nullptr)
            return false;

        if (dfs(root->left, p, v))
        {
            v.push_back(root);
            return true;
        }

        if (dfs(root->right, p, v))
        {
            v.push_back(root);
            return true;
        }

        if (root->val == p->val)
        {
            v.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> dp;
        std::vector<TreeNode*> dq;

        dfs(root, p, dp);
        dfs(root, q, dq);

        int len = std::min(dp.size(), dq.size());

        TreeNode *lowest = nullptr;

        for (int i = dp.size() - 1, j = dq.size() -1; i >= 0 && j >=0; i--, j--)
        {
            if (dp.at(i) == dq.at(j))
            {
                lowest = dp.at(i);
            }
            else
                break;
        }
        
        return lowest;
    }
};

class Solution1
{
public:
    void travestal(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode *parent)
    {
        if (root == nullptr)
            return;

        travestal(root->left, p, q, root);
        travestal(root->right, p, q, root);
        graph[root] = parent;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        travestal(root, p, q, nullptr);
        TreeNode *parent_p = p;
        TreeNode *result = nullptr;
        // std::cout << "p = " << p->val << ", q = " << q->val << std::endl;
        while (true)
        {

            TreeNode *parent_q = q;
            while (true)
            {
                if (parent_q == parent_p)
                {
                    // std::cout << "result is " << ((parent_p == nullptr) ? "nullptr" : std::to_string(parent_p->val)) << std::endl;
                    result = parent_q;
                    break;
                }

                parent_q = graph[parent_q];
                if (parent_q == nullptr)
                    break;
            }

            parent_p = graph[parent_p];

            if (parent_p == nullptr || result != nullptr)
                break;
        }
        return (result == nullptr) ? root : result;
    }

private:
    std::map<TreeNode *, TreeNode *> graph;
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(5);
    t1->left->left = new TreeNode(6);
    t1->left->right = new TreeNode(2);
    t1->left->right->left = new TreeNode(7);
    t1->left->right->right = new TreeNode(4);
    t1->right = new TreeNode(1);
    t1->right->left = new TreeNode(0);
    t1->right->right = new TreeNode(8);
    print(t1);

    Solution s;
    // auto result = s.lowestCommonAncestor(t1, t1->left, t1->right->right );
    auto result = s.lowestCommonAncestor(t1, t1->left->left, t1->left->right->right );
    std::cout << result->val << std::endl;

    delete_tree(t1);
    return 0;
}