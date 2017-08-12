# 44. Wildcard Matching

Difficulty: Hard

https://leetcode.com/problems/wildcard-matching/description/

Implement wildcard pattern matching with support for '?' and '*'.
```
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
```

Companies: Google, Snapchat, Two Sigma, Facebook, Twitter

Related Topics: Dynamic Programming, Backtracking, Greedy, String

Similar Questions: Regular Expression Matching
