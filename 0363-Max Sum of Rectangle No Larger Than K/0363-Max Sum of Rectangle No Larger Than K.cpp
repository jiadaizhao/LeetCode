class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int maxSum = INT_MIN;
        for (int l = 0; l < n; ++l)
        {
            vector<int> sums(m);
            vector<int> presums(1 + m);
            vector<int> temp(1 + m);
            for (int r = l; r < n; ++r)
            {
                for (int i = 0; i < m; ++i)
                {
                    sums[i] += matrix[i][r];
                    presums[i + 1] = presums[i] + sums[i];
                }
                
                mergeSort(presums, 0, m, temp, k, maxSum);
                if (maxSum == k)
                {
                    return k;
                }
            }
        }
        
        return maxSum;
    }
    
private:
    void mergeSort(vector<int>& presums, int start, int end, vector<int>& temp, int k, int& maxSum)
    {
        if (start < end)
        {
            int mid = start + (end - start) / 2;
            mergeSort(presums, start, mid, temp, k, maxSum);
            mergeSort(presums, mid + 1, end, temp, k, maxSum);
            
            int i = start, j = mid + 1;
            int q = start;
            int p = mid + 1;
            while (i <= mid)
            {
                while (p <= end && presums[p] - presums[i] <= k)
                {
                    maxSum = max(maxSum, presums[p] - presums[i]);
                    ++p;
                }
                
                while (j <= end && presums[j] < presums[i])
                {
                    temp[q++] = presums[j++];
                }
                
                temp[q++] = presums[i++];
            }
            
            while (j <= end)
            {
                temp[q++] = presums[j++];
            }
            
            for (int l = start; l <= end; ++l)
            {
                presums[l] = temp[l];
            }
        }
    }
};
