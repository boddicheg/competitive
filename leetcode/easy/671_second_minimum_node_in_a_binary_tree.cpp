#include <iostream>
#include <vector>
#include <queue>
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
    int travestal(TreeNode* root, int min)
    {
        if (root == nullptr)
            return std::numeric_limits<int>::max();
        if(root->val != min) return root->val;
        return std::min(travestal(root->left, min),  travestal(root->right, min));
    }

    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == nullptr)
            return -1;

        int second_min = travestal(root, root->val);
        return (second_min == std::numeric_limits<int>::max()) ? -1 : second_min;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(3);
    t1->right = new TreeNode(3);
    t1->right->left = new TreeNode(15);
    t1->right->right = new TreeNode(7);
    print(t1);

    int result = s.findSecondMinimumValue(t1);
    std::cout << result << std::endl;

    delete t1->right->left;
    delete t1->right->right;
    delete t1->right;
    delete t1->left;
    delete t1;
    return 0;
}
