#include <iostream>
#include <vector>
#include <set>
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

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:

    void depth(Node* root, int lvl)
    {
        if(root == nullptr)
            return;
        level = std::max(lvl, level);

        if(root->children.empty())
            return;

        for(Node* n: root->children)
            depth(n, lvl + 1);
    }

    int maxDepth(Node *root)
    {
        int result = 0;
        if(root == nullptr)
            return 0;
        depth(root, 1);
        return level;
    }
private:
    int level = std::numeric_limits<int>::min();
};

int main(int argc, char const *argv[])
{
    Solution s;
    return 0;
}
