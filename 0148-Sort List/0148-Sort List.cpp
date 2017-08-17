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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* mid = findMedian(head);
        ListNode* right = sortList(mid->next);
        mid->next = nullptr;
        ListNode* left = sortList(head);
        return mergeTwoLists(left, right);
    }
    
private:
    ListNode* findMedian(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(-1);
        ListNode *p = &dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Real O(1) space
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        
        ListNode* curr = head;
        int len = 0;
        while (curr)
        {
            ++len;
            curr = curr->next;
        }
        
        ListNode dummy(-1);
        ListNode *left, *right, *tail;
        dummy.next = head;
        
        for (int step = 1; step < len; step <<= 1)
        {
            curr = dummy.next;
            tail = &dummy;
            while (curr)
            {
                left = curr;
                right = split(left, step);
                curr = split(right, step);
                tail = mergeTwoLists(left, right, tail);
            }
        }
        
        return dummy.next;
    }
    
    ListNode* split(ListNode* head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        
        for (int i = 1; head && i < n; ++i)
        {
            head = head->next;
        }
        
        if (head == nullptr)
        {
            return nullptr;
        }
        
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2, ListNode* head)
    {
        ListNode* p;
        for (p = head; l1 && l2; p = p->next)
        {
            if (l1->val <= l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
        }
        
        p->next = (l1 == nullptr) ? l2 : l1;
        while (p->next)
        {
            p = p->next;
        }
        return p;
    }
};
