/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Note: k can be larger than the linked list length.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head;
        }
        
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }
        
        k %= len;
        ListNode* p = head;
        for (int i = 0; i < len - k - 1; ++i) {
            p = p->next;
        }
        tail->next = head;
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
