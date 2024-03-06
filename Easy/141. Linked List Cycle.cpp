/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       map<ListNode*,int>mp;
       ListNode* current = head;

       while(current!=NULL)
       {
            if(mp.find(current) != mp.end())
                return true;
            
            mp[current]++;
            current = current->next;
       }

       return false;
    }
};