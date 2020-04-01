class Codec:
    def encode(self, strs: [str]) -> str:
        """Encodes a list of strings to a single string.
        """
        return ''.join(str(len(s)) + '@' + s for s in strs)
        

    def decode(self, s: str) -> [str]:
        """Decodes a single string to a list of strings.
        """
        result = []
        i = 0
        while i < len(s):
            j = s.find('@', i)
            i = j + 1 + int(s[i: j])
            result.append(s[j + 1: i])
        
        return result


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
