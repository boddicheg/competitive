/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

size_t size(ListNode * list)
{
    size_t result = 0;
    ListNode* tmp = list;
    while(tmp != nullptr)
    {
        result++;
        tmp = tmp->next;
    }
    return result;
}

int at_list(ListNode* list, size_t index)
{
    size_t _index = 0;
    ListNode* tmp = list;
    while(tmp != nullptr)
    {
        if(index == _index)
            return tmp->val;
        else
        {
            _index++;
            tmp = tmp->next;
        }
    }
    return -1;
}

inline size_t rev_idx(size_t idx, size_t size)
{
    return size - idx - 1;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        size_t size_first = size(l1);
        size_t size_second = size(l2);

        ListNode* top = l1;
        ListNode* bottom = l2;
        ListNode* result = nullptr;

        size_t top_size = size_first;
        size_t bottom_size = size_second;

        if (size_first < size_second)
        {
            top = l2;
            top_size = size_second;
            bottom = l1;
            bottom_size = size_first;
        }

        size_t diff = std::abs(size_first - size_second);
        size_t max_size = std::max(size_first, size_second);

        bool buffer = false;

        for (int i = 0; i < max_size; ++i)
        {
            // Calculating  digit
            int result_digit = 0;
            if (i < max_size - diff)
            {
                int top_digit = at_list(top, rev_idx(i, top_size));
                int bottom_digit = at_list(bottom, rev_idx(i, bottom_size));
                if (bottom_digit == -1)
                {
                    bottom_digit = 0;
                }

                int sum = top_digit + bottom_digit;
                if (buffer)
                {
                    sum++;
                    buffer = false;
                }

                if (sum >= 10)
                {
                    buffer = true;
                    sum -= 10;
                }
                result_digit = sum;
            }
            else
            {
                result_digit = at_list(top, rev_idx(i, top_size));
                if (buffer)
                {
                    result_digit++;
                    buffer = false;
                }
                if (result_digit >= 10)
                {
                    buffer = true;
                    result_digit -= 10;
                }
            }

            // Add to list
            if(result == nullptr)
            {
                result = new ListNode(result_digit);
                result->next = nullptr;
            }
            else
            {
                ListNode* tmp = new ListNode(result_digit);
                tmp->next = result;
                result = tmp;
            }
        }

        if (buffer)
        {
            ListNode* tmp = new ListNode(1);
            tmp->next = result;
            result = tmp;
        }

        return result;
    }
};