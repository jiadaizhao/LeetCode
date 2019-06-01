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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        
        vector<int> result(vals.size());
        stack<int> St;
        for (int i = vals.size() - 1; i >= 0; --i) {
            while (!St.empty() && St.top() <= vals[i]) {
                St.pop();
            }
            if (St.size()) {
                result[i] = St.top();
            }
            St.push(vals[i]);
        }
        
        return result;
    }
};
