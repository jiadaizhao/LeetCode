class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        result = []
        for i in range(sideLength):
            for j in range(sideLength):
                result.append(((width - 1 - i) // sideLength + 1) * ((height - 1 - j) // sideLength + 1))
        
        return sum(sorted(result, reverse=True)[:maxOnes])
