class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        while sx <= tx and sy <= ty:
            if tx < ty:
                if sx == tx:
                    return (ty - sy) % sx == 0
                else:
                    ty %= tx
            else:
                if sy == ty:
                    return (tx - sx) % sy == 0
                else:
                    tx %= ty
        return False
