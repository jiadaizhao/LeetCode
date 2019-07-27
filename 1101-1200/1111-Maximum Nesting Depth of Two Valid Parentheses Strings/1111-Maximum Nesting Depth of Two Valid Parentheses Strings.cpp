class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int A = 0, B = 0;
        vector<int> result(seq.size());
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                if (A < B) {
                    ++A;
                }
                else {
                    ++B;
                    result[i] = 1;
                }
            }
            else {
                if (A > B) {
                    --A;
                }
                else {
                    --B;
                    result[i] = 1;
                }
            }
        }

        return result;
    }
};
