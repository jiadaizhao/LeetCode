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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = &dummy;
        while (p) {
            p = reverseNextK(p, k);
        }
        
        return dummy.next;
    }
    
private:
    ListNode* reverseNextK(ListNode* head, int k) {
        ListNode* curr = head->next;
        ListNode* tail = head->next;
        for (int i = 0; i < k; ++i) {
            if (tail == nullptr) {
                return nullptr;
            }
            tail = tail->next;
        }
        
        head->next = reverseList(curr, tail);
        return curr;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail) {
        ListNode* curr = head;
        ListNode* prev = tail;
        while (curr != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
