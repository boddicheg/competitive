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
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *_head = head;
        ListNode *_prev = nullptr;

        while (_head != nullptr)
        {
            if (_head->val == val)
            {
                ListNode *tmp = _head->next;
                delete _head;
                _head = tmp;

                if (_prev != nullptr)
                    _prev->next = _head;
                else
                {
                    // Change original head
                    head = head->next;
                    _head = head;
                }
            }
            else
            {
                _prev = _head;
                if (_head != nullptr)
                    _head = _head->next;
            }

        }
        return head;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *_head1 = head;

    while (_head1 != nullptr)
    {
        std::cout << _head1->val << " ";
        _head1 = _head1->next;
    }
    std::cout << endl;

    Solution s;
    ListNode *result = s.removeElements(head, 3);

    _head1 = result;

    while (_head1 != nullptr)
    {
        std::cout << _head1->val << " ";
        _head1 = _head1->next;
    }
    std::cout << endl;

    return 0;
}
