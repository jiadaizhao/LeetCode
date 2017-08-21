class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int right = max(min(C, G), left);
        int bottom = max(B, F);
        int up = max(min(D, H), bottom);
        return (C - A) * (D - B) + (G - E) * (H - F) - (right - left) * (up - bottom);
    }
};
