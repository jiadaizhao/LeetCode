class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = ' '.join(sentence) + ' '
        start = 0
        for i in range(rows):
            start += cols
            if s[start % len(s)] == ' ':
                start += 1
            else:
                while start > 0 and s[(start - 1) % len(s)] != ' ':
                    start -= 1
                    
        return start // len(s)
