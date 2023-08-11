#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ~ListNode()
    {
        std::cout << "~ListNode is " << val << std::endl;
    }
};

void print(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode* tmp = node->next;
        node->next = tmp->next;
        node->val = tmp->val;
        delete tmp;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    print(head);
    s.deleteNode(head->next);
    print(head);

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
