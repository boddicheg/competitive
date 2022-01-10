#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]";// << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

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
    void travestal(TreeNode *root, int given_sum)
    {
        if (root == nullptr)
            return;

        test(root, given_sum);
        travestal(root->left, given_sum);
        travestal(root->right, given_sum);
    }

    void test(TreeNode *root, int sum)
    {
        if(root == nullptr)
            return;

        std::cout << root->val << std::endl;

        if(root->val == sum)
            ipaths++;

        test(root->left, sum - root->val);
        test(root->right, sum - root->val);
    }

    int pathSum(TreeNode *root, int sum)
    {
        travestal(root, sum);
        return ipaths;
    }
private:
    int ipaths = 0;
};

int main(int argc, char const *argv[])
{
    Solution s;

    TreeNode *t1 = new TreeNode(10);
    t1->left = new TreeNode(5);
    t1->right = new TreeNode(-3);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(2);
    t1->left->right->right = new TreeNode(1);
    t1->left->left->left = new TreeNode(3);
    t1->left->left->right = new TreeNode(-2);

    t1->right->right = new TreeNode(11);
    print(t1);

    std::cout << s.pathSum(t1, 8) << std::endl;

    delete t1->left->left;
    delete t1->left->right;
    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}
