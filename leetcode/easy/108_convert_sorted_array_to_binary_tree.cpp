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

int g_nodes = 0;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
        g_nodes++;
    }

    ~TreeNode()
    {
        g_nodes--;
    }

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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if(nums.size() == 0) return nullptr;

        int mid = nums.size() / 2.0;
        TreeNode *root = new TreeNode(nums.at(mid));

        std::vector<int> v0{ nums.begin(), nums.begin()+ mid };
        std::vector<int> v1{ nums.begin()+ mid + 1, nums.end() };

        root->left = sortedArrayToBST(v0);
        root->right = sortedArrayToBST(v1);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    {
        Solution s;
        vector<int> nums = {-20, -10, -3, 0, 5, 9, 13, 16 };
        TreeNode *t = s.sortedArrayToBST(nums);
        print(t);
    }

    std::cout << "Nodes left: " << g_nodes << std::endl;
    return 0;
}
