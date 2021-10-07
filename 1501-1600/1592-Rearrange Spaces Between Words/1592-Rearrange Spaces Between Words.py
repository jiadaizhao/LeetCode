class Solution:
    def reorderSpaces(self, text: str) -> str:
        space = text.count(' ')
        words = text.split()
        if len(words) == 1:
            return words[0] + ' ' * space
        bet, end = divmod(space, len(words) - 1)
        return (' '*bet).join(words) + ' ' * end
