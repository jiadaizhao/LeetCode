class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> presum;
        presum.insert(0);
        int count = 0;
        long long sum = 0;
        for (int num : nums) {
            sum += num;
            auto low = presum.lower_bound(sum - upper);
            auto up = presum.upper_bound(sum - lower);
            count += distance(low, up);
            presum.insert(sum);
        }
        
        return count;
    }
};

// Divide and Conquer
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> presum(1 + n);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
        
        int count = 0;
        vector<long long> temp(1 + n);
        mergeSort(presum, 0, n, lower, upper, temp, count);
        
        return count;
    }
    
private:
    void mergeSort(vector<long long>& presum, int start, int end, int lower, int upper, vector<long long>& temp, int& count) {
        if (start < end) {
            int mid = start + (end -start) / 2;
            mergeSort(presum, start, mid, lower, upper, temp, count);
            mergeSort(presum, mid + 1, end, lower, upper, temp, count);
            merge(presum, start, mid, end, lower, upper, temp, count);
        }
    }
    
    void merge(vector<long long>& presum, int start, int mid, int end, int lower, int upper, vector<long long>& temp, int& count) {
        int i = start, j = mid + 1;
        int k = start;
        int p = mid + 1, q = mid + 1;
        while (i <= mid) {
            while (p <= end && presum[p] - presum[i] < (long)lower) {
                ++p;
            }
            
            while (q <= end && presum[q] - presum[i] <= (long)upper) {
                ++q;
            }
            
            count += q - p;
            while (j <= end && presum[i] > presum[j]) {
                temp[k++] = presum[j++];
            }
            
            temp[k++] = presum[i++];
        }
        
        while (j <= end) {
            temp[k++] = presum[j++];
        }
        
        for (int i = start; i <= end; ++i) {
            presum[i] = temp[i];
        }
    }
};
