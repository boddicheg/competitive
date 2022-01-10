#include <iostream>
#include <queue>
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
    if (root == nullptr) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr) {
          output += "null, ";
          continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

void print(TreeNode* root)
{
    std::cout << to_string(root) << std::endl;
}

TreeNode *trimBST(TreeNode *root, int L, int R)
{
    if (root == nullptr) return nullptr;

    if(root->val < L) return trimBST(root->right, L, R);
    if(root->val > R) return trimBST(root->left, L, R);

    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}

int main(int argc, char const *argv[])
{
    TreeNode *t1 = new TreeNode(3);
    t1->left = new TreeNode(1);
    t1->right = new TreeNode(4);
    t1->left->right = new TreeNode(2);
    print(t1);

    TreeNode *t2 = trimBST(t1, 3, 4);
    print(t2);

    delete t1->left;
    delete t1->right;
    delete t1;

    return 0;
}