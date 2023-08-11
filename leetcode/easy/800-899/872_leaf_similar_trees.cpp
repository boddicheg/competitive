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

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    void _leaf(TreeNode *root, std::vector<int> &result)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(root->val);
            return;
        }

        _leaf(root->left, result);
        _leaf(root->right, result);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> v1;
        _leaf(root1, v1);
        std::vector<int> v2;
        _leaf(root2, v2);

        return std::equal(v1.begin(), v1.end(), v2.begin());
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->right->right = new TreeNode(5);
    print(t1);

    TreeNode *t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);
    t2->left->left = new TreeNode(5);
    t2->right->right = new TreeNode(5);
    print(t2);

    Solution s;
    std::cout << std::boolalpha << s.leafSimilar(t1, t2) << std::endl;

    delete t2->right->left;
    delete t2->right->right;
    delete t2->right;
    delete t2->left;
    delete t2;

    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}