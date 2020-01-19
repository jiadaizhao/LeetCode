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

# Bidirection BFS
import collections
class Solution2:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []
        table = collections.defaultdict(list)
        L = len(beginWord)
        for word in wordList:
            for i in range(L):
                table[word[:i] + '*' + word[i + 1:]].append(word)
                
        nextWord = collections.defaultdict(list)
        findPath = False
        headIsFront = True
        visitedBegin = set([beginWord])
        visitedEnd = set([endWord])
        visited = set([beginWord, endWord])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                headIsFront = not headIsFront
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            
            temp = set()
            for w in visitedBegin:
                for i in range(L):
                    nw = w[:i] + '*' + w[i+1:]
                    for word in table[nw]:
                        if word in visitedEnd:
                            if headIsFront:
                                nextWord[w].append(word)
                            else:
                                nextWord[word].append(w)
                            findPath = True                        
                        elif word not in visited:
                            if headIsFront:
                                nextWord[w].append(word)
                            else:
                                nextWord[word].append(w)
                            temp.add(word)                

            if findPath:
                break
            visitedBegin = temp
            visited.update(temp)

        result = []
        def dfs(currw):
            if currw == endWord:
                result.append(path[:])
                return
            
            for nextw in nextWord[currw]:
                path.append(nextw)
                dfs(nextw)
                path.pop()
        
        if findPath:
            path = [beginWord]
            dfs(beginWord)
        return result
