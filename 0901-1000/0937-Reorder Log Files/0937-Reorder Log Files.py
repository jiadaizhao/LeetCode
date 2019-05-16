class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def corder(log):
            identifier, detail = log.split(None, 1)
            return (0, detail, identifier) if detail[0].isalpha() else (1,)
        return sorted(logs, key=corder)
