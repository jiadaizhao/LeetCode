class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int left = 0, right = (int)(tokens.size()) - 1;
        int point = 0, maxPoint = 0;
        while (left <= right) {
            if (P >= tokens[left]) {
                P -= tokens[left++];
                maxPoint = max(maxPoint, ++point);
            }
            else if (point > 0) {
                P += tokens[right--];
                --point;
            }
            else {
                break;
            }
        }
        return maxPoint;
    }
};
