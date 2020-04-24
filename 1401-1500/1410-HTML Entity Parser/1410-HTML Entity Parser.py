class Solution:
    def entityParser(self, text: str) -> str:
        start = curr = 0
        result = list(text)
        table = {"&quot;": '\"', "&apos;": '\'', "&amp;": '&',
                "&gt;": '>', "&lt;": '<', "&frasl;": '/'}
        
        for c in text:
            result[curr] = c
            if c == '&':
                start = curr
            elif c == ';' and 4 <= curr - start + 1 <= 7:
                s = ''.join(result[start: curr + 1])
                if s in table:
                    result[start] = table[s]
                    curr = start
                start = curr + 1
            curr += 1

        return ''.join(result[:curr])
