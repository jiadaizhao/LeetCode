class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        vector<int> result(2);
        while (start < end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
            {
                result[0] = start + 1;
                result[1] = end + 1;
                break;
            }
            else if (sum < target)
            {
                ++start;
            }
            else
            {
                --end;
            }
        }
        
        return result;
    }
};
