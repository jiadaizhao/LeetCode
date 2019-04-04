class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num <= 1:
            return False
        sum = 1
        i = 2
        while i * i <= num:
            if num % i == 0:
                sum += i
                if i*i != num:
                    sum += num // i
                if sum > num:
                    break
            i += 1
        return sum == num
