class Solution:
    def numberToWords(self, num: int) -> str:
        below_100 = ['Twenty', 'Thirty', 'Forty', 'Fifty', 'Sixty', 'Seventy', 'Eighty', 'Ninety']
        below_20 = ['One', 'Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten',
                   'Eleven', 'Twelve', 'Thirteen', 'Fourteen', 'Fifteen', 'Sixteen', 'Seventeen', 'Eighteen', 'Nineteen']
        result = []
        def numberToString(num):
            if num >= 10 ** 9:
                numberToString(num // (10**9))
                result.append('Billion')
                numberToString(num % (10 ** 9))
            elif num >= 10 ** 6:
                numberToString(num // (10**6))
                result.append('Million')
                numberToString(num % (10 ** 6))
            elif num >= 1000:
                numberToString(num // 1000)
                result.append('Thousand')
                numberToString(num % 1000)
            elif num >= 100:
                numberToString(num // 100)
                result.append('Hundred')
                numberToString(num % 100)
            elif num >= 20:
                result.append(below_100[num // 10 - 2])
                numberToString(num % 10)
            elif num >= 1:
                result.append(below_20[num - 1])
        
        if num == 0:
            return 'Zero'
        else:
            numberToString(num)
            return ' '.join(result)
