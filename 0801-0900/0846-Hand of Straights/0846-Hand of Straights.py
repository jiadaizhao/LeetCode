import collections
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        freq = collections.Counter(hand)
        prev = -1
        start = collections.deque()
        open = 0
        for curr in sorted(freq):
            count = freq[curr]
            if (open > 0 and curr > prev + 1) or count < open:
                return False
            start.append(count - open)
            open = count

            if len(start) == W:
                open -= start.popleft()

            prev = curr

        return open == 0
