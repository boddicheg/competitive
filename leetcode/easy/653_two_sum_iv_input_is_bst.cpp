#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    bool findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return k == 0;

        std::vector<int> nums;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == nullptr)
            {
                continue;
            }

            nums.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        std::cout << std::endl;

        std::map<int, int> pairs;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            int first = nums.at(i);
            auto it = pairs.find(k - first);
            if (it != pairs.end() && it->second != i)
                return true;
            else
                pairs[first] = i;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *t1 = new TreeNode(5);
    t1->left = new TreeNode(3);
    t1->left->left = new TreeNode(2);
    t1->left->right = new TreeNode(4);
    t1->right = new TreeNode(6);
    t1->right->right = new TreeNode(7);
    print(t1);

    std::cout << std::boolalpha << s.findTarget(t1, 5) << std::endl;

    delete t1->left;
    delete t1->right;
    delete t1;

    return 0;
}
