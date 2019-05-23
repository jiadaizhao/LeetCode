from fractions import Fraction
class Solution:
    def isRationalEqual(self, S: str, T: str) -> bool:
        def convert(s):
            if '.' not in s:
                return Fraction(int(s), 1)
            i = s.index('.')
            result = Fraction(int(s[:i]), 1)
            s = s[i + 1:]
            if '(' not in s:
                if s:
                    result += Fraction(int(s), 10 ** len(s))
                return result

            i = s.index('(')
            if i > 0:
                result += Fraction(int(s[:i]), 10 ** i)
            s = s[i + 1 : -1]
            result += Fraction(int(s), 10 ** i * (10 ** len(s) - 1))
            return result

        return convert(S) == convert(T)
