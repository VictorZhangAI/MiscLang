/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *node)
    {
            int length = 0;
            while(node)
            {
                length++;
                node = node->next;
            }
            return length;
    }
    ListNode *addLists(ListNode *l1, ListNode *l2, int& carry)
    {
        if(!l1) return NULL;
        ListNode *nextNode = addLists(l1->next, l2->next, carry);
        int total = l1->val + l2->val + carry;
        carry = total / 10;
        return new ListNode(total % 10, nextNode);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1), len2 = getLength(l2);
        while(len1 < len2)
        {
            l1 = new ListNode(0, l1);
            len1++;
        }
        while(len2 < len1)
        {
            l2 = new ListNode(0, l2);
            len2++;
        }
        int carry = 0;
        ListNode *result = addLists(l1, l2, carry);
        if(carry > 0)
        {
            result = new ListNode(carry, result);
        }
        return result;
    }
};
