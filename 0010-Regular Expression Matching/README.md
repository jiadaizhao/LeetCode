# 10. Regular Expression Matching

Difficulty: Hard

https://leetcode.com/problems/regular-expression-matching/description/

Implement regular expression matching with support for '.' and '*'.

```
'.' Matches any single character.

'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
```

Companies: Google, Uber, Airbnb, Facebook, Twitter

Related Topics: Dynamic Programming, Backtracking, String

Similar Questions: Wildcard Matching
