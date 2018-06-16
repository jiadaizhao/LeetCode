class Solution:
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        result = list(dominoes)
        last = -1
        for i in range(len(dominoes)):
            if dominoes[i] == 'L':
                if last != -1 and dominoes[last] == 'R':
                    j = (i + last) // 2
                    if ((i + last) & 1) == 0:
                        result[j] = '.'
                else:
                    j = last
                for k in range(j + 1, i):
                    result[k] = 'L'
            if dominoes[i] != '.':
                last = i
            elif last != -1 and dominoes[last] == 'R':
                result[i] = 'R'
        return ''.join(result)
