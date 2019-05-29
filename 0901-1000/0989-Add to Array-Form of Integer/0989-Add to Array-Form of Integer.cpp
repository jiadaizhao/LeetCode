class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> result;
        int carry = 0, i = A.size() - 1;
        while (K || carry) {
            int sum = K % 10 + carry;
            if (i >= 0) {
                sum += A[i--];
            }
            carry = sum / 10;
            result.push_back(sum % 10);
            K /= 10;
        }
        
        while (i >= 0) {
            result.push_back(A[i--]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
