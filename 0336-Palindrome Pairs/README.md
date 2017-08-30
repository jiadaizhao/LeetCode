# 336. Palindrome Pairs

Difficulty: Hard

https://leetcode.com/problems/palindrome-pairs/description/

Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

**Example 1:**  
Given words = ["bat", "tab", "cat"]  
Return [[0, 1], [1, 0]]  
The palindromes are ["battab", "tabbat"]

**Example 2:**  
Given words = ["abcd", "dcba", "lls", "s", "sssll"]  
Return [[0, 1], [1, 0], [3, 2], [2, 4]]  
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

**Credits:**  
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Companies: Google, Airbnb

Related Topic: Hash Table, String, Trie

Similar Questions: Longest Palindrome Substring, Shortest Palindrome
