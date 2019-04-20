class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);        
        int sum = 0;
        int result = 0;
        int i = 0;
        while (sum < target) {
            sum += ++i;
        }
        
        if ((sum - target) % 2 == 0) {
            result = i; 
        }
        else if (i % 2 == 0){
            result = i + 1;
        }
        else {
            result = i + 2;
        }
        
        return result;
    }
};
