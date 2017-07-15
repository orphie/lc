class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.data = []
        self.min = None

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        self.data.append(x)
        if (self.min == None) or (self.min > x):
            self.min = x
        
    def pop(self):
        """
        :rtype: void
        """
        last = self.data.pop()
        if last == self.min:
            if not self.data:
                self.min = None
            else:
                self.min = min(self.data)
        return last
    
    def top(self):
        """
        :rtype: int
        """
        return self.data[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min    


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
