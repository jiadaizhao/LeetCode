class Solution:
    def corpFlightBookings(self, bookings: List[List[int]], n: int) -> List[int]:
        result = [0] * n
        for i, j, k in bookings:
            result[i - 1] += k
            if j < n:
                result[j] -= k
        
        for i in range(1, len(result)):
            result[i] += result[i - 1]

        return result
