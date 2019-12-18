class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices < cheeseSlices * 2  ||
            (tomatoSlices & 1) || tomatoSlices > cheeseSlices * 4)
            return {};

        return {tomatoSlices / 2  - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
    }
};
