import collections
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []
        table = collections.defaultdict(list)
        L = len(beginWord)
        for word in wordList:
            for i in range(L):
                table[word[:i] + '*' + word[i + 1:]].append(word)
        distance = {beginWord: 0}
        nextWord = collections.defaultdict(list)
        findPath = False
        Q = collections.deque([(beginWord, 0)])
        while Q:
            currw, step = Q.popleft()
            if currw == endWord:
                findPath = True
                break
            for i in range(L):
                nextw = currw[:i] + '*' + currw[i+1:]
                for word in table[nextw]:
                    if word not in distance:
                        Q.append((word, step + 1))
                        distance[word] = step + 1
                    nextWord[currw].append(word)
                    
        result = []
        def dfs(currw):
            if currw == endWord:
                result.append(path[:])
                return
            
            for nextw in nextWord[currw]:
                if distance[nextw] == distance[currw] + 1:
                    path.append(nextw)
                    dfs(nextw)
                    path.pop()
        if findPath:
            path = [beginWord]
            dfs(beginWord)
        return result
