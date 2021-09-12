class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        def f(z):
            ans = 0
            for a, b in positions:
                ans += ((z[0] - a)**2 + (z[1] - b)**2)**(0.5)
            return ans 
        import numpy as np
        import scipy.optimize as opt

        x = []
        y = []
        for a, b in positions:
            x.append(a)
            y.append(b)
        x = np.array(x)
        y = np.array(y)
        res = opt.minimize(f, np.array([x.mean(), y.mean()]))

        return res.fun
