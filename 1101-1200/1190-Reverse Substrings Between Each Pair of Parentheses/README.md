# 1190. Reverse Substrings Between Each Pair of Parentheses

Difficulty: Medium

https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

Given a string s that consists of lower case English letters and brackets. 

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any bracket.

**Example 1:**
```
Input: s = "(abcd)"
Output: "dcba"
```

**Example 2:**
```
Input: s = "(u(love)i)"
Output: "iloveu"
```

**Example 3:**
```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
```

**Example 4:**
```
Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
```

**Constraints:**

* 0 <= s.length <= 2000
* s only contains lower case English characters and parentheses.
* It's guaranteed that all parentheses are balanced.
