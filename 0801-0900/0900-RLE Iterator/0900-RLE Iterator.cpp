class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        this->A = A;
        start = num = 0;
    }
    
    int next(int n) {
        while (start < A.size()) {
            if (num + n <= A[start]) {
                num += n;
                return A[start + 1];
            }
            else {
                n -= A[start] - num;
                num = 0;
                start += 2;
            }
        }
        return -1;
    }
    
private:
    vector<int> A;
    int start, num;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
