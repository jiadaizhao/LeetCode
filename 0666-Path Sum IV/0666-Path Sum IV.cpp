class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<vector<int>> sum(5, vector<int>(8));
        for (int num : nums) {
            int level = num / 100;
            int index = num % 100 / 10 - 1;
            int val = num % 10;
            sum[level][index] += sum[level - 1][index / 2] + val;
        }
        
        int result = 0;
        for (int i = 1; i < 5; ++i) {
            for (int j = 0; j < i * 2; ++j) {
                if (i == 4 || (sum[i][j] && !sum[i + 1][j * 2] && !sum[i + 1][j * 2 + 1])) {
                    result += sum[i][j];
                }
            }
        }
        
        return result;
    }
};

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        for (int num : nums) {
            table[num / 10] = num % 10; 
        }
        
        int sum = 0;
        traverse(nums[0] / 10, 0, sum);
        return sum;
    }
    
private:
    unordered_map<int, int> table;
    void traverse(int root, int preSum, int& sum) {
        int level = root / 10;
        int index = root % 10;
        int curSum = preSum + table[root];
        
        int left = (level + 1) * 10 + 2 * index - 1;
        int right = (level + 1) * 10 + 2 * index;
        if (table.find(left) == table.end() && table.find(right) == table.end()) {
            sum += curSum;
        }
        
        if (table.find(left) != table.end()) {
            traverse(left, curSum, sum);
        }
        if (table.find(right) != table.end()) {
            traverse(right, curSum, sum);
        }
    }
};
