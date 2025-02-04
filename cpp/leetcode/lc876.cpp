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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        int sp = 0;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            sp++, sp++;
        }
        if(sp % 2 == 0)
            return slow;
        else
            return slow->next;
    }
};
