class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        product = [0] * (len(num1) + len(num2))
        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                p1 = i + j
                p2 = i + j + 1
                sum = int(num1[i]) * int(num2[j]) + product[p2]
                product[p1] += sum // 10
                product[p2] = sum % 10
                
        return ''.join(map(str, product)).lstrip('0') or '0'
