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

class Solution
{
public:
    void _levelOrderBottom(TreeNode *root, int lvl)
    {
        if(root == nullptr) return;

        if(result.size() < lvl || result.empty())
            result.push_back({});

        result.at(lvl - 1).push_back(root->val);

        _levelOrderBottom(root->left, lvl + 1);
        _levelOrderBottom(root->right, lvl + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if(root == nullptr)
            return result;

        _levelOrderBottom(root, 1);
        std::reverse(result.begin(), result.end());
        return result;
    }
private:
    vector<vector<int>> result;
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(9);
    t1->right = new TreeNode(20);
    t1->left->left = new TreeNode(1);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    print(t1);

    Solution s;
    auto result = s.levelOrderBottom(t1);

    for(const auto& e: result)
        print(e);

    delete t1->left->left;
    delete t1->left->right;
    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}