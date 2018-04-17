import collections
class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        table = collections.Counter()
        for cpdomain in cpdomains:
            num, s = cpdomain.split()
            num = int(num)
            for i in range(len(s) - 1, 0, -1):
                if s[i] == '.':
                    table[s[i + 1 :]] += num
            table[s] += num
        return ["%d %s" % (table[k], k) for k in table]
