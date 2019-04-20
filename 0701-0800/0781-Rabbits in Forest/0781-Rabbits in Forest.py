import collections
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        return sum((v + k) // (k + 1) * (k + 1) for k, v in collections.Counter(answers).items())
