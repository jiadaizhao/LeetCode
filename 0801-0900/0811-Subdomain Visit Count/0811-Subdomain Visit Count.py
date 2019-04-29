import collections
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        table = collections.Counter()
        for cpdomain in cpdomains:
            wi = cpdomain.index(' ')
            count = int(cpdomain[:wi])
            names = cpdomain[wi+1:].split('.')
            for i in range(len(names)):
                table['.'.join(names[i:])] += count
        return ['{} {}'.format(v, k) for k, v in table.items()]
