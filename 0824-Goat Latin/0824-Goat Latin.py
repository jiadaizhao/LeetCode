class Solution:
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        def convert(word):
            if word[0] not in 'aeiouAEIOU':
                word = word[1:] + word[:1]
            return word + "ma"
        return ' '.join(convert(word) + 'a' * i for i, word in enumerate(S.split(), 1))
