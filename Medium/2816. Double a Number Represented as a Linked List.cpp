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
// New Comment
// For main
class Solution {
    public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev; 
        
    }
    ListNode* doubleIt(ListNode* head) {
        
        
        head = reverse(head);

        ListNode* current = head;
        int carry = 0;
        
        while (current) {
            int newVal = current->val * 2 + carry;
            current->val = newVal % 10;
            carry = newVal / 10;
            if (!current->next && carry > 0) {
                
                
                current->next = new ListNode(carry);
                break;
            }
            current = current->next;
        }
        return reverse(head);
    }
};
