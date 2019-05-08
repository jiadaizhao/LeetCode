class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int low = 0, high = people.size() - 1, total = 0;
        while (low <= high) {
            total += 1;
            if (people[low] + people[high] <= limit) {
                low += 1;
            }
            high -= 1;
        }
        return total;
    }
};
