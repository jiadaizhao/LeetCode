import collections

class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        ban = set(banned)
        count = collections.Counter(word.strip("!?',;.") for word in paragraph.lower().split())

        result, maxCount = '', 0
        for word in count:
            if count[word] > maxCount and word not in ban:
                result, maxCount = word, count[word]
        return result

sol = Solution()
paragraph = "Bob. hIt, baLl"
banned = ["bob", "hit"]
result = sol.mostCommonWord(paragraph, banned)
print(result)