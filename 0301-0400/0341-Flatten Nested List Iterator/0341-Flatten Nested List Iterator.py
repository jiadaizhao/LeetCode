# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.St = [[nestedList, 0]]
        

    def next(self):
        """
        :rtype: int
        """
        nl, index = self.St[-1]
        self.St[-1][1] += 1
        return nl[index].getInteger()
        

    def hasNext(self):
        """
        :rtype: bool
        """
        while self.St:
            nl, index = self.St[-1]
            if index == len(nl):
                self.St.pop()
            else:
                ni = nl[index]
                if ni.isInteger():
                    return True
                self.St[-1][1] += 1
                self.St.append([ni.getList(), 0])
        return False
        

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.St = nestedList[::-1]

    def next(self):
        """
        :rtype: int
        """
        return self.St.pop().getInteger()

    def hasNext(self):
        """
        :rtype: bool
        """
        while self.St:
            ni = self.St[-1]
            if ni.isInteger():
                return True
            
            self.St.pop()
            self.St += ni.getList()[::-1]

        return False
