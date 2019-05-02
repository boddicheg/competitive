#include <iostream>
#include <stack>
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

class Solution // 5%
{
public:
    void _postorder(Node *root, int lvl)
    {
        if(root == nullptr) return;

        for(Node* e: root->children)
            _postorder(e, lvl + 1);
        result.push_back(root->val);
    }

    vector<int> postorder(Node* root)
    {
        if(root == nullptr)
            return result;

        _postorder(root, 1);
        return result;
    }
private:
    vector<int> result;
};

class Solution1
{
public:
    vector<int> postorder(Node* root)
    {
        if(root == nullptr) return {};
        vector<int> result;
        std::stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* t = st.top();
            st.pop();

            for(Node* c: t->children)
                st.push(c);

            result.push_back(t->val);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}