class Solution:
    def stoneGameVI(self, aliceValues: List[int], bobValues: List[int]) -> int:
        s = sorted(zip(aliceValues, bobValues), key=sum, reverse=True)
        alice = sum(a for a, b in s[::2])
        bob = sum(b for a, b in s[1::2])
        if alice < bob:
            return -1
        elif alice > bob:
            return 1
        else:
            return 0
