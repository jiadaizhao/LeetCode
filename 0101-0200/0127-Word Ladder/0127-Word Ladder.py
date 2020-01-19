import collections
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        table = collections.defaultdict(list)
        L = len(beginWord)
        for word in wordList:
            for i in range(L):
                table[word[:i] + '*' + word[i + 1:]].append(word)
                
        Q = collections.deque([(beginWord, 1)])
        visited = set([beginWord])
        while Q:
            currw, step = Q.popleft()
            for i in range(L):
                nextw = currw[:i] + '*' + currw[i+1:]
                for word in table[nextw]:
                    if word == endWord:
                        return step + 1
                    if word not in visited:
                        Q.append((word, step + 1))
                        visited.add(word)
        return 0

# Bidirection
class Solution2:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        table = collections.defaultdict(list)
        L = len(beginWord)
        for word in wordList:
            for i in range(L):
                table[word[:i] + '*' + word[i + 1:]].append(word)
        
        qBegin = collections.deque([(beginWord, 1)])
        visitedBegin = {beginWord: 1}
        qEnd = collections.deque([(endWord, 1)])
        visitedEnd = {endWord: 1}
        def visitWord(Q, visited1, visited2):
            currw, step = Q.popleft()
            for i in range(L):
                nextw = currw[:i] + '*' + currw[i+1:]
                for word in table[nextw]:
                    if word in visited2:
                        return step + visited2[word]
                    if word not in visited1:
                        visited1[word] = step + 1
                        Q.append((word, step + 1))
                    
            return None
        while qBegin and qEnd:
            step = visitWord(qBegin, visitedBegin, visitedEnd)
            if step:
                return step
            step = visitWord(qEnd, visitedEnd, visitedBegin)
            if step:
                return step

        return 0


# Faster bidirection with swap
class Solution3:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        table = collections.defaultdict(list)
        L = len(beginWord)
        for word in wordList:
            for i in range(L):
                table[word[:i] + '*' + word[i + 1:]].append(word)
                
        step = 1
        visitedBegin = set([beginWord])
        visitedEnd = set([endWord])
        visited = set([beginWord, endWord])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            
            step += 1
            temp = set()
            for w in visitedBegin:
                for i in range(L):
                    nw = w[:i] + '*' + w[i+1:]
                    for word in table[nw]:
                        if word in visitedEnd:
                            return step
                        if word not in visited:
                            temp.add(word)
                            visited.add(word)                

            visitedBegin = temp

        return 0
