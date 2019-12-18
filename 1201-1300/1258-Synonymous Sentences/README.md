# 1258. Synonymous Sentences

Difficulty: Medium

https://leetcode.com/problems/synonymous-sentences/

Given a list of pairs of equivalent words synonyms and a sentence text, Return all possible synonymous sentences sorted lexicographically.

**Example 1:**
```
Input:
synonyms = [["happy","joy"],["sad","sorrow"],["joy","cheerful"]],
text = "I am happy today but was sad yesterday"
Output:
["I am cheerful today but was sad yesterday",
​​​​​​​"I am cheerful today but was sorrow yesterday",
"I am happy today but was sad yesterday",
"I am happy today but was sorrow yesterday",
"I am joy today but was sad yesterday",
"I am joy today but was sorrow yesterday"]
```

**Constraints:**

* 0 <= synonyms.length <= 10
* synonyms[i].length == 2
* synonyms[0] != synonyms[1]
* All words consist of at most 10 English letters only.
* text is a single space separated sentence of at most 10 words.
