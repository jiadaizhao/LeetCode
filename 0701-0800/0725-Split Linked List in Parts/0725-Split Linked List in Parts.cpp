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
        
        int count = len / k, remain = len % k;
        vector<ListNode*> result(k);
        head = root;
        for (int i = 0; i < k && head; ++i) {
            result[i] = head;
            ListNode* prev = nullptr;
            for (int j = 0; j < count; ++j) {
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
        
        return result;
    }
};
