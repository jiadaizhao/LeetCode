class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        clips.sort()
        maxT = count = i = 0
        while i < len(clips):
            start, maxEnd = clips[i]
            if start > maxT:
                return -1
            while i < len(clips) and clips[i][0] <= maxT:
                maxEnd = max(maxEnd, clips[i][1])
                i += 1
            count += 1
            if maxEnd >= T:
                return count
            maxT = maxEnd
        return -1
