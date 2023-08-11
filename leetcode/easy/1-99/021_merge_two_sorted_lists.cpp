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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *c_result = nullptr;
        ListNode *result = c_result;
        ListNode *c_l1 = l1;
        ListNode *c_l2 = l2;

        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }

        while (true)
        {
            int val1 = (c_l1) ? c_l1->val : std::numeric_limits<int>::max();
            int val2 = (c_l2) ? c_l2->val : std::numeric_limits<int>::max();

            if (val1 <= val2)
            {
                if (c_result == nullptr)
                {
                    c_result = c_l1;
                    result = c_result;
                }
                else
                {
                    ListNode *tmp = c_l1;
                    c_result->next = tmp;
                    c_result = c_result->next;
                }
                c_l1 = c_l1->next;
            }
            else if (val1 > val2)
            {
                if (c_result == nullptr)
                {
                    c_result = c_l2;
                    result = c_result;
                }
                else
                {
                    ListNode *tmp = c_l2;
                    c_result->next = tmp;
                    c_result = c_result->next;
                }
                c_l2 = c_l2->next;
            }

            if (c_l1 == nullptr && c_l2 == nullptr)
                break;
        }

        return result;
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
    head1->next->next->next = new ListNode(9);

    print(head);
    print(head1);
    ListNode* result = s.mergeTwoLists(head, head1);
    print(result);

    delete head1->next->next->next;
    delete head1->next->next;
    delete head1->next;
    delete head1;

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
    return 0;
}
