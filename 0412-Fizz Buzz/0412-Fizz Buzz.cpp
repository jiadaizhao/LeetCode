class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            bool div3 = (i % 3 == 0);
            bool div5 = (i % 5 == 0);
            if (div3 && div5) {
                result.push_back("FizzBuzz");
            }
            else if (div3) {
                result.push_back("Fizz");
            }
            else if (div5) {
                result.push_back("Buzz");
            }
            else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }
};
