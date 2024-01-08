# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        res = [];
        def fun(root):
            if(root):
                fun(root.left)
                if(root.val <= high and root.val >= low):
                    res.append(root.val)
                fun(root.right)
        fun(root)
        return sum(res);
        