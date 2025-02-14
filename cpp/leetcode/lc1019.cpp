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
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode *temp = head;
        vector<int> ll;
        while(temp)
        {
            ll.push_back(temp->val);
            temp = temp->next;
        }

        stack<int> st;
        for(int i = 0; i < ll.size(); i++)
        {
            while(!st.empty() && ll[i] > ll[st.top()])
            {
                ll[st.top()] = ll[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
        {
            ll[st.top()] = 0;
            st.pop();
        }
        return ll;
    }
};
