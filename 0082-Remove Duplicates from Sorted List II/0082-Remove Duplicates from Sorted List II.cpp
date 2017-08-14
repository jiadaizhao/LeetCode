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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode dummy = ListNode(-1);
        ListNode* p = &dummy;
        ListNode* prev = head;
        ListNode* curr = head->next;
        bool duplicate = false;
        while (curr)
        {
            if (curr->val != prev->val)
            {
                if (!duplicate)
                {
                    p->next = prev;
                    p = p->next;
                }
                duplicate = false;
                prev = curr;
            }
            else
            {
                duplicate = true;
            }
            curr = curr->next;
        }
        
        if (!duplicate)
        {
            p->next = prev;
            p = p->next;
        }
        
        p->next = nullptr;
        
        return dummy.next;
    }
};
