# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root == None:
            return []
        ret = []
        if root.left != None:
            leftSub = self.binaryTreePaths(root.left)
            for c in leftSub:
                ret.append(str(root.val) + "->" + c)
        if root.right != None:
            rightSub = self.binaryTreePaths(root.right)
            for c in rightSub:
                ret.append(str(root.val) + "->" + c)
        if not root.left and not root.right:
            ret.append(str(root.val))
        return ret
