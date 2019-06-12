#ifndef __BST_HPP__
#define __BST_HPP__

#include <iostream>
#include <string>
#include <queue>

namespace structures {

template<typename T>
struct Node
{
    T val;
    Node<T> *left;
    Node<T> *right;

    Node(T x) : val(x), left(nullptr), right(nullptr) {}
    ~Node() { std::cout << "Node with value " << val << " deleted." << std::endl; }
};

// Adapter for leetcode
using TreeNode = Node<int>;

template<typename T>
std::string to_string(Node<T>* root)
{
    std::string result;

    if (root == nullptr)
        return "[]";

    std::queue<Node<T>*> q;
    q.push(root);

    while(!q.empty())
    {
        Node<T>* node = q.front();
        q.pop();
        if (node == nullptr)
        {
            result += "null, ";
            continue;
        }

        result += std::to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return std::string(result.begin(), result.end() - 2);
}

template<typename T>
std::ostream& operator << (std::ostream& ss, Node<T>* root)
{
    ss << to_string(root);
    return ss;
}

template<typename T>
void remove(Node<T>* root)
{
    if (root == nullptr)
        return;

    std::queue<Node<T>*> q;
    q.push(root);
    while(!q.empty())
    {
        Node<T>* node = q.front();
        q.pop();
        if (node == nullptr)
        {
            continue;
        }

        q.push(node->left);
        q.push(node->right);
        delete node;
    }
}

} // end of structures namespace

#endif // end of __BST_HPP__