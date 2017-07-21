# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]   top -> leftTree -> rightTree
        :type inorder: List[int]    leftTree -> top -> rightTree
        :rtype: TreeNode
        """
        if len(inorder) == 0:
            return None
        rootVal     = preorder[0]
        root        = TreeNode(rootVal)
        # find right value
        rootInOrderId   = inorder.index(rootVal)
        leftPreOrder = rightPreOrder = leftInOrder = rightInOrder = []
        if rootInOrderId != len(inorder) - 1:
            rightInOrder    = inorder[rootInOrderId+1:]
        if rootInOrderId != 0:
            leftInOrder  = inorder[:rootInOrderId] 
        if len(leftInOrder) > 0:
            leftPreOrder  = preorder[1:1+len(leftInOrder)]
        if len(rightInOrder) > 0:
            rightPreOrder = preorder[len(preorder)-len(rightInOrder):]
        #print leftPreOrder, leftInOrder, rightPreOrder, rightInOrder
        root.left   = self.buildTree(leftPreOrder, leftInOrder)
        root.right  = self.buildTree(rightPreOrder, rightInOrder)
        return root
