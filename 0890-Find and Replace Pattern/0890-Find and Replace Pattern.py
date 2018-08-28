class Solution:
    def findAndReplacePattern(self, words, pattern):
        """
        :type words: List[str]
        :type pattern: str
        :rtype: List[str]
        """
        res = []
        for word in words:
            table = {}
            mapped = set()
            flag = True
            for i in range(len(pattern)):
                if pattern[i] not in table:
                    if word[i] in mapped:
                        flag = False
                        break
                    table[pattern[i]] = word[i]
                    mapped.add(word[i])
                elif table[pattern[i]] != word[i]:
                    flag = False
                    break
            if flag:
                res.append(word)
        return res
