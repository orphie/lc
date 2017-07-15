class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """ 
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        i = 0
        left = 0
        while 1:
            [retValue,ret] = self.check(i,gas,cost)
            if ret == True:
                return i
            if retValue <= i:
                return -1
            i = retValue 
        return -1
        
    def check(self, i, gas, cost):
        cur = i
        step = 0
        left = 0
        while gas[cur]+left >= cost[cur]:
            left = gas[cur] + left - cost[cur]
            if cur == len(gas)-1:
                cur = 0
            else:
                cur = cur + 1
            step = step + 1
            if step == len(gas):
                return [0, True]
        if cur == len(gas)-1:
            cur = 0
        else:
            cur = cur + 1
        return [cur, False]            
