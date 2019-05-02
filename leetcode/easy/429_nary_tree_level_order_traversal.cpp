#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Node {
public:
    int val = NULL;
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
    void _levelOrder(Node *root, int lvl)
    {
        if(root == nullptr) return;


        for(Node* e: root->children)
            _levelOrder(e, lvl + 1);

        if(result.size() < lvl || result.empty())
            result.push_back({});

        result.at(lvl - 1).push_back(root->val);
    }

    vector<vector<int>> levelOrder(Node* root)
    {
        if(root == nullptr)
            return result;

        _levelOrder(root, 1);
        return result;
    }
private:
    vector<vector<int>> result;
};

int main(int argc, char const *argv[])
{
    return 0;
}