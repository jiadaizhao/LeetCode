class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        maxTime = prev = 0
        maxKey = 'a'
        for key, time in zip(keysPressed, releaseTimes):
            curr = time - prev
            if curr > maxTime or (curr == maxTime and key > maxKey):
                maxTime = curr
                maxKey = key
            prev = time
        return maxKey
