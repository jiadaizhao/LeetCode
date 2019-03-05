class Solution:
    def intToRoman(self, num: int) -> str:
        radix = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbol = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        result = []
        for r, s in zip(radix, symbol):            
            result.append(s * (num // r))
            num %= r
            if num == 0:
                break
        return ''.join(result)
