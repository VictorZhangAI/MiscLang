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
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head;
        ListNode *q = NULL;
        queue<ListNode *> s;
        while(p != NULL)
        {
            s.push(p);
            p = p->next;
        }
        while(!s.empty())
        {
            q = s.front();
            s.pop();
            q->next = p;
            p = q;
        }
        return q;
    }
};
