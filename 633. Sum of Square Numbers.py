class Solution(object):
    def judgeSquareSum(self, c):
        """
        :type c: int
        :rtype: bool
        """
        num = 0
        goal = math.sqrt(c)
        while num <= goal:
            left = c - num*num
            if self.isPerfectSquare(left):
                return True
            num = num + 1
        return False
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        return True if int(math.sqrt(num))** 2 == num else False
