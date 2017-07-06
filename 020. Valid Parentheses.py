class Solution(object):
    def isValid(self, s):
        """             
        :type s: str                                                     
        :rtype: bool
        """         
        pair = {')':'(', '}':'{', ']':'['}
        queue = []
        for c in s: 
            if c in pair.keys():
                if (len(queue) == 0) or (queue.pop() != pair[c]): 
                    return False
            else:
                queue.append(c)
        return True if len(queue) == 0 else False 
