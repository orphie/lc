# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        curlist = [root]
        self.bfs([root])
    def bfs(self, curlist):
        if not curlist:
            return
        nextlist = []
        for id in range(0,len(curlist)):
            if id == len(curlist) - 1:
                curlist[id].next = None
            else:
                curlist[id].next = curlist[id+1]
            if curlist[id].left:
                nextlist.append(curlist[id].left)
            if curlist[id].right:
                nextlist.append(curlist[id].right)
        self.bfs(nextlist)
