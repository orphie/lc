class Solution(object):
    def split(self, start, end, nums):
        if (start == end):
            return start
        middle = float(start + end)/2
        print start, end, middle
        #print middle
        if middle in [start, end]:
            return middle
        #split(middle, nums)
        #print int(middle)
        left = 0
        right = 0
        for n in nums:
            if n < start or n > end:
                continue
            if n < middle:
                left = left + 1
            elif n > middle:
                right = right + 1
        
        if left == right:
            return int(middle)
        elif left > right:
            return self.split(start, int(middle), nums)
        else:
            nextV = int(middle) + 1 if (start == int(middle)) else int(middle)
            return self.split(nextV, end, nums)

        
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 1
        end = len(nums) -1
        return int(self.split(start, end, nums))
