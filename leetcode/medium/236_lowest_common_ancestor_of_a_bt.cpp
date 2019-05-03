#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

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
    Solution s;

    TreeNode *t1 = new TreeNode(6);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(0);
    t1->left->right = new TreeNode(4);
    t1->left->right->left = new TreeNode(3);
    t1->left->right->right = new TreeNode(5);

    t1->right = new TreeNode(8);
    t1->right->left = new TreeNode(7);
    t1->right->right = new TreeNode(9);
    print(t1);

    std::cout << s.lowestCommonAncestor(t1, t1->left->left, t1->left->right->right) << std::endl;

    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;

    return 0;
}
