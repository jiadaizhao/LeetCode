/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int d = depth(nestedList);
        return helper(nestedList, d);
    }

private:
    int depth(vector<NestedInteger>& nestedList) {
        int d = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                d = max(d, 1);
            }
            else {
                d = max(d, 1 + depth(ni.getList()));
            }
        }
        
        return d;
    }

    int helper(vector<NestedInteger>& nestedList, int weight) {
        int sum = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * weight;
            }
            else {
                sum += helper(ni.getList(), weight - 1);
            }
        }
        
        return sum;
    }
};

// Iterative method
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int unweighted = 0, weighted = 0;
        while (!nestedList.empty()) {
            vector<NestedInteger> nextLevel;
            for (NestedInteger ni : nestedList) {
                if (ni.isInteger()) {
                    unweighted += ni.getInteger();
                }                    
                else {
                    vector<NestedInteger>& temp = ni.getList();
                    for (NestedInteger& t : temp) {
                        nextLevel.push_back(t);
                    }                    
                }                    
            }
            weighted += unweighted;
            nestedList = nextLevel;
        }
        return weighted;
    }
};
