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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            if (!prev->next || prev->next->val > curr->val) {
                prev = &dummy;
            }
            
            while (prev->next && prev->next->val <= curr->val) {
                prev = prev->next;
            }
            
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        
        return dummy.next;
    }
};
