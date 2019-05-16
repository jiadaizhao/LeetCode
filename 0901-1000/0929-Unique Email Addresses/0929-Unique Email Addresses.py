class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        table = set()
        for email in emails:
            local, domain = email.split('@')
            index = local.find('+')
            if index != -1:
                local = local[:index]
            table.add(''.join(local.split('.')) + '@' + domain)
        return len(table)
