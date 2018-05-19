class Solution:
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """        
        S = list(S)
        for i, x, y in sorted(zip(indexes, sources, targets), reverse = True):
            if all(i + k < len(S) and S[i+k] == x[k] for k in range(len(x))):
                S[i:i+len(x)] = list(y)

        return ''.join(S)
