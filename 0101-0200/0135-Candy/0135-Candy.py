class Solution:
    def candy(self, ratings: List[int]) -> int:
        if len(ratings) == 0:
            return 0
        total = peak = 1
        down = 0
        for i in range(1, len(ratings)):
            if ratings[i] >= ratings[i - 1]:
                if down > 0:
                    total += down * (down + 1) // 2
                    if down >= peak:
                        total += down + 1 - peak
                    down = 0
                    peak = 1
                peak = 1 if ratings[i] == ratings[i - 1] else peak + 1
                total += peak
            else:
                down += 1
                
        if down > 0:
            total += down * (down + 1) // 2
            if down >= peak:
                total += down + 1 - peak
        return total
