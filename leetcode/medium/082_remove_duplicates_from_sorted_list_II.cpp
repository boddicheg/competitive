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
        std::cout << head->val << "(" << head << ") -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr) return nullptr;

        ListNode *tmp = head;
        ListNode *prev = nullptr;
        int current = tmp->val;
        bool is_seq = false;

        while (tmp != nullptr && tmp->next != nullptr)
        {
            // std::cout << "Pair is: " << current << "(" << tmp << ")" << " -> " << tmp->next->val << "(" << tmp->next << ") " << std::endl;
            if (current == tmp->next->val)
            {
                is_seq = true;
                ListNode *candidate = tmp->next;
                // std::cout << "Remove next element " << tmp->next->val << "(" << tmp->next << ") " << std::endl;
                if (tmp->next != nullptr)
                    tmp->next = tmp->next->next;
                delete candidate;
            }
            else
            {
                if (is_seq)
                {
                    // std::cout << "Remove current as a last element of sequence: " << tmp->val << "(" << tmp << ") " << "(" << prev << ") " << std::endl;
                    if (tmp == head)
                    {
                        // std::cout << "Current node " << "(" << tmp << ") " << " for deletion is head " << "(" << head << ") " << std::endl;
                        ListNode *new_head = tmp->next;
                        delete tmp;
                        head = new_head;
                        prev = nullptr;
                        is_seq = false;
                    }
                    else
                    {
                        // std::cout << "Remove current as non-head element: " << tmp->val << "(" << tmp << ")" << " prev is " << prev->val << "(" << prev << ") " << std::endl;
                        ListNode *candidate = tmp;
                        if (prev != nullptr)
                            prev->next = tmp->next;
                        delete candidate;
                        tmp = prev;
                        is_seq = false;
                    }
                }
                prev = tmp;
                tmp = tmp->next;
                current = tmp->val;

            }
        }

        if (is_seq)
        {
            // std::cout << "Remove last element: " << tmp->val << "(" << tmp << ")" << " prev is " << prev->val << "(" << prev << ")" << std::endl;
            ListNode *last = tmp;
            if (prev != nullptr)
                prev->next = nullptr;
            if (head == tmp)
                head = nullptr;
            delete tmp;
            tmp = nullptr;
        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = new ListNode(7);



    ListNode *result = s.deleteDuplicates(head);
    print(result);

    // delete head->next->next->next;
    // delete head->next->next;
    // delete head->next;
    // delete head;
    return 0;
}
