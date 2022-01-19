#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

#define watch(x) std::cout << (#x) << " is " << (x) << std::endl

template<typename T>
void print(const T &container)
{
    std::cout << "[ ";
    for (const auto &e : container)
        std::cout << e << " ";
    std::cout << "]" << std::endl;
}

std::ostream &operator<<(std::ostream &ss, const std::pair<int, int> &p)
{
    ss << "[ " << p.first << ", " << p.second << " ]";
    return ss;
}

template<typename T>
std::ostream &operator<<(std::ostream &ss, const std::vector<T> &c)
{
    ss << "[ ";
    for (const auto &e : c)
        ss << e << " ";
    ss << "]" << std::endl;
    return ss;
}

static int x = []() { std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0; }();


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        while (head->next != nullptr)
        {
            if (head >= head->next)
                return head->next;
            head = head->next;
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode *head5 = new ListNode(5);
    // head5->next = nullptr;
    ListNode *head4 = new ListNode(4);
    head4->next = head5;
    ListNode *head3 = new ListNode(3);
    head3->next = head4;
    ListNode *head2 = new ListNode(2);
    head2->next = head3;
    ListNode *head1 = new ListNode(1);
    head1->next = head2;
    ListNode *head = new ListNode(0);
    head->next = head1;
    // Loop
    head5->next = head4;

    auto result = s.detectCycle(head);
    std::cout << "Result: " << (result ? result->val : -1) << std::endl;
    return 0;
}
