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

    bool _isPalindrome(ListNode **left, ListNode *right)
    {
        if(right == nullptr)
            return true;

        bool result = _isPalindrome(left, right->next);
        if(!result) return false;
        bool result1 = (*left)->val == right->val;
        (*left) = (*left)->next;

        return result1;
    }

    bool isPalindrome(ListNode *head)
    {
        return _isPalindrome(&head, head);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);

    std::cout << std::boolalpha <<  s.isPalindrome(head) << std::endl;

    print(head);

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
