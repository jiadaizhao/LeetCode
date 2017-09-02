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
    NestedInteger deserialize(string s) {
        stack<NestedInteger> St;
        St.push(NestedInteger());
        string num;
        for (char c : s)
        {
            if (c == '[')
            {
                St.push(NestedInteger());
            }
            else if (c == '-' || isdigit(c))
            {
                num += c;
            }
            else
            {
                if (num.size())
                {
                    St.top().add(NestedInteger(stoi(num)));
                    num = "";
                }
                
                if (c == ']')
                {
                    NestedInteger temp = St.top();
                    St.pop();
                    St.top().add(temp);
                }
            }
        }
        
        if (num.size())
        {
            St.top().add(NestedInteger(stoi(num)));
            num = "";
        }
        
        return St.top().getList().front();
    }
};
