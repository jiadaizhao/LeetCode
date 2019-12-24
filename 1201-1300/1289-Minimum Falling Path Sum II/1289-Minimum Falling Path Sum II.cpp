class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < arr[0].size(); ++j) {
            if (min1 == -1 || arr[0][j] < arr[0][min1]) {
                min2 = min1;
                min1 = j;
            }
            else if (min2 == -1 || arr[0][j] < arr[0][min2]) {
                min2 = j;
            }
        }
        
        for (int i = 1; i < arr.size(); ++i) {
            int currMin1 = -1, currMin2 = -1;
            for (int j = 0; j < arr[i].size(); ++j) {
                if (j == min1) {
                    arr[i][j] += arr[i - 1][min2];
                }
                else {
                    arr[i][j] += arr[i - 1][min1];
                }
                
                if (currMin1 == -1 || arr[i][j] < arr[i][currMin1]) {
                    currMin2 = currMin1;
                    currMin1 = j;
                }
                else if (currMin2 == -1 || arr[i][j] < arr[i][currMin2]) {
                    currMin2 = j;
                }
            }
            min1 = currMin1;
            min2 = currMin2;
        }
        
        return arr.back()[min1];
    }
};
