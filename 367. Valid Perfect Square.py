class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 0: 
            return False
        start   = 0
        end     = num
        return self.check(start,end,num)
    def check(self,start,end,num):
            if start*start==num or end*end==num:
                return True
            if start*start > num:
                return False
            elif end*end < num:
                return False
    
            middle = (start+end)/2
            if middle == start or middle == end:
                return False
            
            if middle*middle > num:
                end = middle
                return self.check(start,end,num)
            elif middle*middle < num:
                start = middle
                return self.check(start,end,num)
            else:
                return True
            
