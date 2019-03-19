class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        table = {}
        def dfs(s):
            if s in table:
                return table[s]
            
            result = []
            for i in range(len(s)):
                if not s[i].isdigit():
                    result.extend([a + b if s[i] == '+' else a - b if s[i] == '-' else a * b    
                                   for a in dfs(s[:i]) for b in dfs(s[i+1:])])
                    
            if not result:
                result = [int(s)]
            table[s] = result
            return result
        
        return dfs(input)
