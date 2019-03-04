class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                continue;
            }

            int slow = getNext(nums, i), fast = getNext(nums, getNext(nums, i));
            while (nums[slow] * nums[i] > 0 && nums[fast] * nums[i] > 0) {
                if (slow == fast) {
                    if (slow == getNext(nums, slow)) {
                        break;
                    }
                    return true;
                }
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }

            slow = i;
            while (nums[slow] * nums[i] > 0) {
                int next = getNext(nums, slow);
                nums[slow] = 0;
                slow = next;
            } 
        }

        return false;
    }

private:
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        return (i + nums[i] + n) % n;
    }
};
