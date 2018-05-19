class Solution:
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        at = S.find('@')
        if at == -1:
            S = re.sub(r'[^0-9]', '', S)
            return ['', '+*-', '+**-', '+***-'][len(S) - 10] + '***-***-' + S[-4:]
        else:
            return (S[0] + '*****' + S[at - 1:]).lower()
