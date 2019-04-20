import collections
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        table = collections.defaultdict(set)
        for A, B, C in allowed:
            table[A, B].add(C)
        
        cache = {}
        def solve(curr):
            if len(curr) == 1:
                return True
            if curr in cache:
                return cache[curr]
            cache[curr] = any(solve(cand) for cand in build(curr, [], 0))
            return cache[curr]
        
        def build(curr, path, start):
            if start == len(curr) - 1:
                yield ''.join(path)
            else:
                for C in table[curr[start], curr[start + 1]]:
                    path.append(C)
                    for result in build(curr, path, start + 1):
                        yield result
                    path.pop()
                    
        return solve(bottom)

class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        table = collections.defaultdict(set)
        for A, B, C in allowed:
            table[A, B].add(C)
        
        cache = {}
        def dfs(s, start, path):
            if start == len(s) - 1:
                if len(s) == 2:
                    cache[s] = True
                    return True
                if path in cache:
                    return cache[path]
                return dfs(path, 0, '')
            
            cache[s] = any(dfs(s, start + 1, path + C) for C in table[s[start], s[start + 1]])
            return cache[s]
                    
        return dfs(bottom, 0, '')
