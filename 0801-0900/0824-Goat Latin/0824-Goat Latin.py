class Solution:
    def toGoatLatin(self, S: str) -> str:
        def convert(word):
            if word[0] not in 'aeiouAEIOU':
                word = word[1:] + word[0]
            return word + 'ma'
        return ' '.join(convert(word) + 'a'*i for i, word in enumerate(S.split(), 1))
