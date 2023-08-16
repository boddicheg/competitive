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

class Solution
{
public:

    void levels(TreeNode *root, int lvl)
    {
        if (root == nullptr) return;

        m_lvls[lvl].push_back(root->val);

        levels(root->left, lvl + 1);
        levels(root->right, lvl + 1);
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> result;
        levels(root, 0);
        for (const auto &e : m_lvls)
            result.push_back(std::accumulate(e.second.begin(), e.second.end(), 0.0) / e.second.size());
        return result;
    }
private:
    map<int, vector<double>> m_lvls;
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    print(t1);

    Solution s;
    vector<double> result = s.averageOfLevels(t1);
    for (const auto &e : result)
        std::cout << e << " ";

    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}