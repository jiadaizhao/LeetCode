class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long prev = 0, curr;
        for (int i = 0; i < n; ++i)
        {
            vector<vector<int>> A(2, vector<int>(2));
            A[0][0] = points[(i + 1) % n][0] - points[i][0];
            A[0][1] = points[(i + 1) % n][1] - points[i][1];
            A[1][0] = points[(i + 2) % n][0] - points[(i + 1) % n][0];
            A[1][1] = points[(i + 2) % n][1] - points[(i + 1) % n][1];
            curr = det2(A);
            if (curr)
            {
                if (curr * prev < 0)
                {
                    return false;
                }
                prev = curr;
            }
        }
        
        return true;
    }
    
private:
    long det2(vector<vector<int>>& A)
    {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
};
