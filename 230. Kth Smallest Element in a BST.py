# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        return self.visit(root,0,k)[0]
    def visit(self, node, cur, k):
        if node:
            [val,cur] = self.visit(node.left, cur, k)
            if cur == k:
                return [val,cur]
            cur = cur + 1
            if cur == k:
                return [node.val,cur]
            return self.visit(node.right, cur, k)
        return [0,cur]
