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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode dummy1 = ListNode(-1);
        ListNode dummy2 = ListNode(-1);
        ListNode* p1 = &dummy1;
        ListNode* p2 = &dummy2;
        bool odd = true;
        while (head) {
            if (odd) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            
            head = head->next;
            odd = !odd;
        }
        
        p1->next = dummy2.next;
        p2->next = nullptr;
        return dummy1.next;
    }
};
