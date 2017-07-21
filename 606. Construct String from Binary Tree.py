# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def tree2str(self, t):
        """
        :type t: TreeNode
        :rtype: str
        """
        if t == None:
            return ""
        
        curStr = str(t.val)
        if t.left == None and t.right == None:
            pass
        elif t.left == None:
            curStr += "()" + "(" + self.tree2str(t.right) + ")"    
        elif t.right == None:
            curStr += "(" + self.tree2str(t.left) + ")"
        else:
            curStr += "(" + self.tree2str(t.left) + ")" + "(" + self.tree2str(t.right) + ")"
        return curStr
