class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int root = INT_MIN;
        stack<int> St;
        for (int num : preorder) {
            if (num < root) {
                return false;
            }
            while (!St.empty() && St.top() < num) {
                root = St.top();
                St.pop();
            }
            
            St.push(num);
        }
        
        return true;
    }
};

// O(1) space, use input array as stack
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int root = INT_MIN;
        int i = 0;
        for (int num : preorder) {
            if (num < root) {
                return false;
            }
            while (i && preorder[i - 1] < num) {
                root = preorder[--i];
            }
            
            preorder[i++] = num;
        }
        
        return true;
    }
};
