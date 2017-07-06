class Solution(object):
    def trap(self, height):
        """ 
        :type height: List[int]
        :rtype: int
        """
        if len(height) in [0,1,2]:
            return 0
        m = max(height)
        peak = [i for i, j in enumerate(height) if j == m]
        
        if len(peak) == 1:
            biggest = peak[0]
            temp = height[:biggest] + height[biggest+1:]
            peak.append(height.index(max(temp)))
        ret = self.merge(height, peak[0], peak[1])
        return ret

    def merge(self, height, peak, secondPeak):
        ret = 0
        print height, peak, secondPeak
        for i in range(min(peak,secondPeak)+1, max(peak,secondPeak)):
            ret = ret + (height[secondPeak] - height[i]) 
            print i, ret
        nextHeight = height[:min(peak,secondPeak)] + height[max(peak,secondPeak):]
        return ret + self.trap(nextHeight)
