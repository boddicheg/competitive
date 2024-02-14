#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

int g_nodes_created = 0;

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

struct Node
{
    Node *next[27] = { nullptr };
};

class Trie
{
public:
    Trie()
        : head(new Node())
    {}

    ~Trie()
    {
        deleteNode(head);
    }

    void deleteNode(Node* head)
    {
        for (int i = 0; i < 27; ++i)
        {
            if(head->next[i] != nullptr)
                deleteNode(head->next[i]);
        }
        delete head;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *tmp = head;
        for (const auto &e : word)
        {
            int idx = e - 97;
            if (tmp->next[idx] == nullptr)
                tmp->next[idx] = new Node();
            tmp = tmp->next[idx];
        }

        tmp->next[26] = new Node();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *tmp = head;
        for (const auto &e : word)
        {
            int idx = e - 97;
            if (tmp->next[idx] != nullptr)
                tmp = tmp->next[idx];
            else
                return false;
        }

        if(tmp->next[26] == nullptr)
            return false;

        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *tmp = head;
        for (const auto &e : prefix)
        {
            int idx = e - 97;
            if (tmp->next[idx] != nullptr)
                tmp = tmp->next[idx];
            else
                return false;
        }
        return true;
    }
private:
    Node *head;
};

int main(int argc, char const *argv[])
{
    {
        Trie trie;

        trie.insert("apple");
        std::cout << boolalpha << trie.search("apple") << std::endl;   // returns true
        std::cout << boolalpha << trie.search("app") << std::endl;     // returns false
        std::cout << boolalpha << trie.startsWith("app") << std::endl; // returns true
        trie.insert("app");
        std::cout << boolalpha << trie.search("app") << std::endl;     // returns true
    }

    std::cout << "Nodes left: " << g_nodes_created << std::endl;
    return 0;
}
