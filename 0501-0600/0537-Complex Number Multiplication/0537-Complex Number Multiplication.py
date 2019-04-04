class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        ra, ia = map(int, a[:-1].split('+'))
        rb, ib = map(int, b[:-1].split('+'))
        return '{0}+{1}i'.format(ra * rb - ia * ib, ra * ib + rb * ia)
