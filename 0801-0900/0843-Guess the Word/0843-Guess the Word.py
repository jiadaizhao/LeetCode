# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master:
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """
import math
class Solution:
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        def match(s1, s2):
            return sum(x == y for x, y in zip(s1, s2))
        
        def calMax(s):
            count = [0] * 7
            for word in wordlist:
                count[match(s, word)] += 1
            return max(count)

        while True:
            minVal = math.inf
            for i, s in enumerate(wordlist):
                curr = calMax(s)
                if curr < minVal:
                    minVal = curr
                    besti = i
            feedback = master.guess(wordlist[besti])
            if feedback == 6:
                break
            wordlist = [word for i, word in enumerate(wordlist) if (i != besti and match(word, wordlist[besti]) == feedback)]
