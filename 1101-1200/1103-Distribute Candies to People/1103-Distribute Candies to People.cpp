class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> result(num_people);
        int curr = 1;
        while (candies > 0) {
            for (int i = 0; i < num_people; ++i) {
                if (candies >= curr + i) {
                    result[i] += curr + i;
                    candies -= curr + i;
                }
                else {
                    result[i] += candies;
                    candies = 0;
                    break;
                }
            }

            curr += num_people;
        }

        return result;
    }
};
