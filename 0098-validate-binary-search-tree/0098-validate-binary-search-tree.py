# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, root: Optional[TreeNode]) -> Tuple[int, bool]:
        if not root: 
            return (float('inf'), float('-inf'), True)    
        
        leftMin, leftMax, leftBST = self.dfs(root.left)
        rightMin, rightMax, rightBST = self.dfs(root.right)

        if not leftBST or not rightBST: 
            return (0, 0, False)

        if leftMax >= root.val:
            return (0, 0, False)

        if rightMin <= root.val:
            return (0, 0, False)

        return (
            min(leftMin, root.val),
            max(rightMax, root.val),
            True
        )

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False

        return self.dfs(root)[2]
