# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        end = n
        ret = guess((start+end)/2)
        while ret != 0:
            if ret < 0:
                #middle is big
                end = (start+end)/2
                ret = guess((start+end)/2)
            elif ret > 0:
                start = (start+end)/2 + 1 if (start+end)/2 == start else (start+end)/2
                ret = guess((start+end)/2)
        return (start+end)/2
