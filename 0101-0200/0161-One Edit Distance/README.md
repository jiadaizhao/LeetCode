# 161. One Edit Distance

Difficulty: Medium

https://leetcode.com/problems/one-edit-distance/

Given two strings s and t, determine if they are both one edit distance apart.

**Note:** 

There are 3 possiblities to satisify one edit distance apart:

1. Insert a character into s to get t
2. Delete a character from s to get t
3. Replace a character of s to get t

**Example 1:**
```
Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
```

**Example 2:**
```
Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
```

**Example 3:**
```
Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
```
