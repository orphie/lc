class Solution(object):
    def removeElement(self, nums, val):
        """ 
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        cur = 0 
        for num in nums:
            if num != val:
                nums[cur] = num 
                cur = cur + 1 
                                                                                                        
        return cur 

        
