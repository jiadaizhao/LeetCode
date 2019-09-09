import collections
class Solution:
    def findNumOfValidWords(self, words: List[str], puzzles: List[str]) -> List[int]:
        table = collections.Counter()
        for word in words:
            curr = 0
            for c in word:
                curr |= (1 << (ord(c) - ord('a')))
            table[curr] += 1
            
        answer = [0] * len(puzzles)
        for i, puzzle in enumerate(puzzles):
            candidates = set([1 << (ord(puzzle[0]) - ord('a'))])
            for c in puzzle[1:]:
                candidates.update(set(cand | (1 << (ord(c) - ord('a'))) for cand in candidates))
            answer[i] = sum(table[cand] for cand in candidates)
        return answer
