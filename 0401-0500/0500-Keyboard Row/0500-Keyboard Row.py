class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        first = set('qwertyuiop')
        second = set('asdfghjkl')
        third = set('zxcvbnm')
        result = []
        for word in words:
            curr = set(word.lower())
            if curr.issubset(first) or curr.issubset(second) or curr.issubset(third):
                result.append(word)
        return result
