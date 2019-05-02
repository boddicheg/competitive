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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = 0, sizeB = 0;
        ListNode* tmpA = headA;
        ListNode* tmpB = headB;

        while(tmpA != nullptr)
        {
            sizeA ++;
            tmpA = tmpA->next;
        }
        while(tmpB != nullptr)
        {
            sizeB ++;
            tmpB = tmpB->next;
        }

        int align = sizeA - sizeB;
        tmpA = headA;
        tmpB = headB;

        while(align > 0)
        {
            tmpA = tmpA->next;
            align--;
        }

        while(align < 0)
        {
            tmpB = tmpB->next;
            align++;
        }

        while(tmpA != tmpB)
        {
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }

        return (tmpA == nullptr) ? nullptr : tmpA;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);


    ListNode *head1 = new ListNode(4);
    head1->next = new ListNode(5);
    head1->next->next = new ListNode(1);
    head1->next->next->next = head->next;

    // print(head);
    // print(head1);

    ListNode* intersection = s.getIntersectionNode(head, head1);
    std::cout << "Intersection is: " << ((intersection != nullptr) ? std::to_string(intersection->val) : "null") << std::endl;
    return 0;
}
