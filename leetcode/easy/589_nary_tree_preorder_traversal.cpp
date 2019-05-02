#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    void _preorder(Node *root, int lvl)
    {
        if(root == nullptr) return;

        result.push_back(root->val);
        for(Node* e: root->children)
            _preorder(e, lvl + 1);
    }

    vector<int> preorder(Node* root)
    {
        if(root == nullptr)
            return result;

        _preorder(root, 1);
        return result;
    }
private:
    vector<int> result;
};

int main(int argc, char const *argv[])
{
    return 0;
}