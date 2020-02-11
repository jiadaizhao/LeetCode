class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        result = []
        if numerator // denominator < 0:
            result.append('-')

        num = abs(numerator)
        den = abs(denominator)
        result.append(str(num // den))
        rem = num % den
        if rem == 0:
            return ''.join(result)
        result.append('.')
        table = {}
        while rem:
            table[rem] = len(result)
            rem *= 10
            result.append(str(rem // den))
            rem %= den
            if rem in table:
                result.insert(table[rem], '(')
                result.append(')')
                break
        return ''.join(result)
