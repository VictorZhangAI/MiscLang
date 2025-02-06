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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *current = head;
        while(current)
        {
            ListNode *next_node = current->next;
            while(next_node != NULL && current->val == next_node->val)
            {
                ListNode *temp = next_node->next;
                delete next_node;
                next_node = temp;
            }
            if(current->next == next_node)
            {
                prev = current;
            }
            else
            {
                prev->next = next_node;
                delete current;
            }
            current = next_node;
        }
        return dummy->next;
    }
};
