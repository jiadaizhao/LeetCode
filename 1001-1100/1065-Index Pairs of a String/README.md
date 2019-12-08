# 1065. Index Pairs of a String

Difficulty: Easy

https://leetcode.com/problems/index-pairs-of-a-string/

Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

**Example 1:**
```
Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
```

**Example 2:**
```
Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
```

**Note:**
1. All strings contains only lowercase English letters.
2. It's guaranteed that all strings in words are different.
3. 1 <= text.length <= 100
4. 1 <= words.length <= 20
5. 1 <= words[i].length <= 50
6. Return the pairs [i,j] in sorted order (i.e. sort them by their first coordinate in case of ties sort them by their second coordinate).
