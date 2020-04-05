class Solution:
    def generateAbbreviations(self, word: str) -> List[str]:
        result = []
        def dfs(start, path, prenum):
            if start == len(word):
                result.append(path)
                return
            dfs(start + 1, path + word[start], False)
            if not prenum:
                for i in range(start, len(word)):
                    dfs(i + 1, path + str(i - start + 1), True)
        
        dfs(0, '', False)
        return result
