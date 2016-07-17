/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <bits/stdc++.h>

class Solution {

public:

    typedef pair<int, int> pii;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pii> lw; // <val, index in lists>
        int n = lists.size();
        
        for (int i = 0; i<n; i++) 
            if (lists[i] != NULL) 
                lw.insert(make_pair(lists[i] -> val, i));
            
        ListNode* head = NULL;
        ListNode* cur = NULL;

        while (!lw.empty())
        {
            pii p = *lw.begin();
            lw.erase(lw.begin());
            int i = p.second;
            lists[i] = lists[i] -> next;
            if (lists[i])
                lw.insert(make_pair(lists[i] -> val, i));
            
            if (!cur) 
            {
                cur = new ListNode(p.first);
                head = cur;
            }
            else 
            {
                cur -> next = new ListNode(p.first);
                cur = cur -> next;
            }
            
        }
        
        return head;
    }
  
};
