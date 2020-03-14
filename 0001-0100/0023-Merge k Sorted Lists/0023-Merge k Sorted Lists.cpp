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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct compare {
            bool operator()(ListNode* l1, ListNode* l2) {
                return l1->val > l2->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* l : lists) {
            if (l) {
                pq.push(l);
            }
        }
        if (pq.empty()) {
            return nullptr;
        }
        ListNode dummy = ListNode(-1);
        ListNode* curr = &dummy;
        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if (curr->next) {
                pq.push(curr->next);
            }
        }
        
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKLists(lists, start, mid);
        ListNode* right = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(-1);
        ListNode* p = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Non-recursive
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        int interval = 1;
        while (interval < n) {
            for (int i = 0; i < n - interval; i += interval * 2) {
                lists[i] = mergeLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        
        return n > 0 ? lists[0] : nullptr;
    }
    
private:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* p = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            }
            else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
