# 935. Knight Dialer

Difficulty: Medium

https://leetcode.com/problems/knight-dialer/

A chess knight can move as indicated in the chess diagram below:

![alt text](knight.png)
![alt text](keypad.png)

This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

How many distinct numbers can you dial in this manner?

Since the answer may be large, output the answer modulo 10^9 + 7.

**Example 1:**
```
Input: 1
Output: 10
```

**Example 2:**
```
Input: 2
Output: 20
```

**Example 3:**
```
Input: 3
Output: 46
```

**Note:**

1. 1 <= N <= 5000
