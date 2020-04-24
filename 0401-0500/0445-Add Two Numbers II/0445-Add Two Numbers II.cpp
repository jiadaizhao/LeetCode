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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> St1, St2;
        while (l1) {
            St1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            St2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* head = nullptr;
        int carry = 0;
        while (!St1.empty() || !St2.empty() || carry) {
            int sum = carry;
            if (!St1.empty()) {
                sum += St1.top();
                St1.pop();
            }
            if (!St2.empty()) {
                sum += St2.top();
                St2.pop();
            }            
            carry = sum / 10;
            sum %= 10;
            ListNode* node = new ListNode(sum);
            node->next = head;
            head = node;
        }
        
        return head;
    }
};
