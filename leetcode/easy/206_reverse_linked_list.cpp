#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode* head)
{
    while(head != nullptr)
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
    ListNode *reverseList(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* new_list = s.reverseList(head);

    print(new_list);

    delete new_list->next->next->next;
    delete new_list->next->next;
    delete new_list->next;
    delete new_list;

    return 0;
}
