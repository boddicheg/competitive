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
    void travel(TreeNode *root, vector<int> &path)
    {
        if (root == nullptr)
            return;

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            std::string buffer;
            for(const auto& e: path)
                buffer += std::to_string(e);
            total_sum += std::stoi(buffer);
            path.pop_back();
            return;
        }

        travel(root->left, path);
        travel(root->right, path);
        path.pop_back();
    }

    int sumNumbers(TreeNode* root)
    {
        vector<int> path;
        travel(root, path);
        return total_sum;
    }

private:
    int total_sum = 0;
};

int main(int argc, char const *argv[])
{
    Solution s;
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    // t1->right->left = new TreeNode(15);
    // t1->left->right = new TreeNode(5);
    print(t1);
    std::cout << s.sumNumbers(t1) << std::endl;
    return 0;
}
