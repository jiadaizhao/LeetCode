class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        result = []
        table = {word[::-1]: i for i, word in enumerate(words)}
        for i, word in enumerate(words):
            for j in range(1, len(word) + 1):
                left = word[:j]
                right = word[j:]
                if left == left[::-1] and right in table and table[right] != i:
                    result.append([table[right], i])
                if right == right[::-1] and left in table and table[left] != i:
                    result.append([i, table[left]])
                    
        if '' in table:
            index = table['']
            for i, word in enumerate(words):
                if i != index and word == word[::-1]:
                    result.append([i, index])
        return result
