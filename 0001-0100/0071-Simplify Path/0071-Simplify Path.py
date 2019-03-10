class Solution:
    def simplifyPath(self, path: str) -> str:
        p = path.split('/')
        St = []
        for s in p:
            if s == '..':
                if St:
                    St.pop()
            elif s != '.' and s != '':
                St.append(s)
        return '/' + '/'.join(St)
