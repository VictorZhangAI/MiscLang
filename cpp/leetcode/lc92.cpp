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
    ListNode* reverseN(ListNode* head, int n)
    {
        if(n == 1)
            return head;
        ListNode* newHead = reverseN(head->next, n - 1);
        ListNode* HeadNext = head->next;
        head->next = HeadNext->next;
        HeadNext->next = head;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1)
            return reverseN(head, right);
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};
