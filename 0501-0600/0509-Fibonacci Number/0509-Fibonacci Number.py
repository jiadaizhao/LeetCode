class Solution:
    def fib(self, N: int) -> int:
        def multiply(A, B):
            result = [[0] * len(B[0]) for _ in range(len(A))]
            for i in range(len(A)):
                for j in range(len(B[0])):
                    for k in range(len(A[0])):                    
                        result[i][j] += A[i][k]*B[k][j]
            return result
                        
        def pow(A, N):
            result = [[1, 0], [0, 1]]
            while N:
                if N&1:
                    result = multiply(result, A)
                A = multiply(A, A)                
                N >>= 1
            return result
                
        A = [[1, 1], [1, 0]]
        result = multiply(pow(A, N), [[0], [1]])
        return result[0][0]
