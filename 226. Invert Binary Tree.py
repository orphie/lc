# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root:
            return None
        temp = root.right
        root.right = root.left
        root.left = temp
        #print root.left.val, root.right.val
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root
        
