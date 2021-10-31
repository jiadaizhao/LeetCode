class Solution:
    def interpret(self, command: str) -> str:
        result = []
        for i, c in enumerate(command):
            if c == 'G':
                result.append(c)
            elif c == '(':
                if command[i + 1] == ')':
                    result.append('o')
                else:
                    result.append('al')
        return ''.join(result)
