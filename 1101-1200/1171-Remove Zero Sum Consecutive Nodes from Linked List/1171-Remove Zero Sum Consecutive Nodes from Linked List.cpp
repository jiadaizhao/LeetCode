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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        dummy.next = head;
        int sum = 0;
        unordered_map<int, ListNode*> table;
        while (curr) {
            sum += curr->val;
            if (table.count(sum)) {
                ListNode* next = table[sum]->next;
                int s = sum + next->val;
                while (s != sum) {
                    table.erase(s);
                    next = next->next;
                    s += next->val;
                }
                table[sum]->next = curr->next;
            }
            else {
                table[sum] = curr;
            }
            curr = curr->next;
        }
        
        return dummy.next;
    }
};
