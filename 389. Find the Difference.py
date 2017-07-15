class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        for c in s:
            if -1 != t.find(c):
                t = t[0:t.find(c)] + t[t.find(c)+1:]
            else:
                return c
        return t[0]
        
