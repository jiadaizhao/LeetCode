import collections
class Solution:
    def arrangeWords(self, text: str) -> str:
        words = text.split()
        table = collections.defaultdict(list)
        for word in words:
            table[len(word)].append(word)
        result = []
        for key in sorted(table):
            result.extend(table[key])

        return ' '.join(result).capitalize()


# Sort is stable
class Solution2:
    def arrangeWords(self, text: str) -> str:
        return ' '.join(sorted(text.split(), key=len)).capitalize()
