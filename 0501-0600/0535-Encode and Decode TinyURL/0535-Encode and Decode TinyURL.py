import random
class Codec:
    def __init__(self):
        self.seed = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
        self.table = {}

        
    def getKey(self):
        return ''.join(random.choice(self.seed) for _ in range(6))


    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        while True:
            key = self.getKey()
            if key not in self.table:
                break
                
        self.table[key] = longUrl
        return key

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return self.table[shortUrl]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
