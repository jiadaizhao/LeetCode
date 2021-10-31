class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(allowed)
        count = 0
        for word in words:
            for c in word:
                if c not in allowed:
                    break
            else:
                count += 1
        return count
