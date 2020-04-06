class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        inc1 = [0] * n
        inc2 = [0] * n
        dec1 = [0] * n
        dec2 = [0] * n
        total = 0
        for j in range(1, n):
            for i in range(j):
                if rating[i] < rating[j]:
                    inc1[j] += 1
                    inc2[j] += inc1[i]
                elif rating[i] > rating[j]:
                    dec1[j] += 1
                    dec2[j] += dec1[i]
            total += inc2[j] + dec2[j]

        return total
