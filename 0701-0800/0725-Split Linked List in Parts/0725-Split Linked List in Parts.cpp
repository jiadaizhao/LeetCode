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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* head = root;
        while (head) {
            ++len;
            head = head->next;
        }
        
        int count = len / k;
        int remain = len % k;
        vector<ListNode*> result;
        head = root;
        while (head) {
            ListNode* prev = nullptr;
            result.push_back(head);
            for (int i = 0; i < count; ++i) {
                prev = head;
                head = head->next;
            }
            
            if (remain > 0) {
                prev = head;
                head = head->next;
                --remain;
            }
            
            prev->next = nullptr;            
        }
        
        result.resize(k);
        return result;
    }
};
