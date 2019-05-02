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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    int _findTilt(TreeNode *root)
    {
        if(root == nullptr)
            return 0;
        int il = _findTilt(root->left);
        int ir = _findTilt(root->right);
        tilt += std::abs(il - ir);
        return root->val + il + ir;
    }

    int findTilt(TreeNode *root)
    {
        _findTilt(root);
        return tilt;
    }
private:
    int tilt = 0;
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    print(t1);

    Solution s;
    int result = s.findTilt(t1);
    std::cout << result << std::endl;

    // delete t1->right->left;
    // delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}