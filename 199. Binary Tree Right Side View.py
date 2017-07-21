# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []     
        curL = [root]
        ret = []
        self.helpProc(curL,ret)
        return ret
    def helpProc(self, curL, ret):
        newL = []
        ret.append(curL[-1].val)
        for node in curL:
            if node.left:
                newL.append(node.left)
            if node.right:
                newL.append(node.right)
        if newL:
            self.helpProc(newL, ret)
            
