class Solution:
    def bagOfTokensScore(self, tokens: List[int], P: int) -> int:
        tokens.sort()
        left = point = maxPoint = 0
        right = len(tokens) - 1
        while left <= right:
            if P >= tokens[left]:
                P -= tokens[left]
                left += 1
                point += 1
                maxPoint = max(maxPoint, point)
            elif point > 0:
                P += tokens[right]
                right -= 1
                point -= 1
            else:
                break
        return maxPoint
