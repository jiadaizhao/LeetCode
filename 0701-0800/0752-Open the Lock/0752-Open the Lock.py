import collections
class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        if '0000' in dead:
            return -1
        turn = 0
        Q = collections.deque(['0000'])
        visited = set(['0000'])
        while Q:
            for i in range(len(Q)):
                s = Q.popleft()
                if s == target:
                    return turn
                for j in range(4):
                    c = s[j]
                    s1 = s[:j] + ('0' if c == '9' else chr(ord(c) + 1)) + s[j + 1:]
                    if s1 not in visited and s1 not in dead:
                        Q.append(s1)
                        visited.add(s1)
                    s2 = s[:j] + ('9' if c == '0' else chr(ord(c) - 1)) + s[j + 1:]
                    if s2 not in visited and s2 not in dead:
                        Q.append(s2)
                        visited.add(s2)
            turn += 1
        return -1

# Bidirection
class Solution2:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        if '0000' in dead:
            return -1
        turn = 0
        visitedBegin = set(['0000'])
        visitedEnd = set([target])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            
            temp = set()
            for s in visitedBegin:
                if s in visitedEnd:
                    return turn
                dead.add(s)
                for j in range(4):
                    c = s[j]
                    s1 = s[:j] + ('0' if c == '9' else chr(ord(c) + 1)) + s[j + 1:]
                    if s1 not in dead:
                        temp.add(s1)
                    s2 = s[:j] + ('9' if c == '0' else chr(ord(c) - 1)) + s[j + 1:]
                    if s2 not in dead:
                        temp.add(s2)
                
            turn += 1
            visitedBegin = temp
        return -1

class Solution3:
    def openLock(self, deadends: List[str], target: str) -> int:
        dead = set(deadends)
        if '0000' in dead:
            return -1
        if target == '0000':
            return 0
        turn = 0
        visitedBegin = set(['0000'])
        visitedEnd = set([target])
        while visitedBegin and visitedEnd:
            if len(visitedBegin) > len(visitedEnd):
                visitedBegin, visitedEnd = visitedEnd, visitedBegin
            
            turn += 1
            temp = set()
            for s in visitedBegin:
                for j in range(4):
                    c = s[j]
                    s1 = s[:j] + ('0' if c == '9' else chr(ord(c) + 1)) + s[j + 1:]
                    s2 = s[:j] + ('9' if c == '0' else chr(ord(c) - 1)) + s[j + 1:]
                    for ns in (s1, s2):
                        if ns in visitedEnd:
                            return turn
                        if ns not in dead:
                            temp.add(ns)
                            dead.add(ns)               
            
            visitedBegin = temp
        return -1
