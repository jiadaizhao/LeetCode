class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        freqCounts = [0] * 12
        
        for word in words:
            freq = word.count(min(word))
            freqCounts[freq] += 1
        
        for i in range(len(freqCounts) - 2, -1, -1):
            freqCounts[i] += freqCounts[i + 1]
        
        answer = [0] * len(queries)
        for i, query in enumerate(queries):
            freq = query.count(min(query))
            answer[i] = freqCounts[freq + 1]
        
        return answer
