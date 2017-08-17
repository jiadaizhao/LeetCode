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
    void reorderList(ListNode* head) {
        if (head == nullptr)
        {
            return;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        head2 = reverseList(head2);
        slow->next = nullptr;
        
        while (head && head2)
        {
            ListNode* next1 = head->next;
            ListNode* next2 = head2->next;
            head->next = head2;
            head2->next = next1;
            head = next1;
            head2 = next2;
        }
    }

private:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};
