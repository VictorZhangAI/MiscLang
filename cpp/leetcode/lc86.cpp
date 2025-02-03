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
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;
        ListNode *lte_head = new ListNode();
        ListNode *gte_head = new ListNode();
        ListNode *temp = head, *lte = lte_head, *gte = gte_head;
        while(temp)
        {
            if(temp->val < x)
            {
                lte->next = temp;
                lte = lte->next;
            }
            else
            {
                gte->next = temp;
                gte = gte->next;
            }
            temp = temp->next;
        }
        gte->next = NULL;
        lte->next = gte_head->next;
        delete gte_head;
        return lte_head->next;
    }
};
