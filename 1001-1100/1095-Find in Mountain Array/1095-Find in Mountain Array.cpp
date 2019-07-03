/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int curr = mountainArr.get(mid);
            if (mountainArr.get(mid + 1) < curr) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        int peak = low;
        int result = min(search(target, mountainArr, 0, peak, true), search(target, mountainArr, peak, n - 1, false));
        return result != INT_MAX ? result : -1;
    }

private:
    int search(int target, MountainArray &mountainArr, int low, int high, bool inc) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int curr = mountainArr.get(mid);
            if (curr == target) {
                return mid;
            }
            else if (curr < target) {
                if (inc) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else {
                if (inc) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        return INT_MAX;
    }
};
