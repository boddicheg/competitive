#include <iostream>
#include <vector>
#include <map>
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr) return nullptr;

        ListNode *tmp = head;
        int current = tmp->val;

        while (tmp->next != nullptr)
        {
            if (current == tmp->next->val)
            {
                ListNode *candidate = tmp->next;
                tmp->next = tmp->next->next;
                delete candidate;
            }
            else
            {
                current = tmp->next->val;
                tmp = tmp->next;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(5);

    ListNode *result = s.deleteDuplicates(head);
    print(result);

    // delete head->next->next->next;
    // delete head->next->next;
    // delete head->next;
    delete head;
    return 0;
}
