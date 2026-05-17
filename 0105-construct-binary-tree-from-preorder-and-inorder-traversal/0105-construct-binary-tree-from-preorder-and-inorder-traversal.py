# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        preIdx = {}
        inIdx = {}
        length = len(preorder)

        for i in range(length):
            preIdx[preorder[i]] = i
            inIdx[inorder[i]] = i

        def recursiveConstructTree(
            root: int, lstLeft: int, lstRight: int, rstLeft: int, rstRight: int
        ) -> Optional[TreeNode]:

            tree = TreeNode(root)

            # LEFT SUBTREE
            if lstLeft <= lstRight:

                lstRootIdx = length

                for i in range(lstLeft, lstRight + 1):
                    lstRootIdx = min(lstRootIdx, preIdx[inorder[i]])

                leftRootVal = preorder[lstRootIdx]
                inorderRootIdx = inIdx[leftRootVal]

                tree.left = recursiveConstructTree(
                    leftRootVal,
                    lstLeft,
                    inorderRootIdx - 1,
                    inorderRootIdx + 1,
                    lstRight,
                )

            else:
                tree.left = None

            # RIGHT SUBTREE
            if rstLeft <= rstRight:

                rstRootIdx = length

                for i in range(rstLeft, rstRight + 1):
                    rstRootIdx = min(rstRootIdx, preIdx[inorder[i]])

                rightRootVal = preorder[rstRootIdx]
                inorderRootIdx = inIdx[rightRootVal]

                tree.right = recursiveConstructTree(
                    rightRootVal,
                    rstLeft,
                    inorderRootIdx - 1,
                    inorderRootIdx + 1,
                    rstRight,
                )

            else:
                tree.right = None

            return tree

        rootIdx = inIdx[preorder[0]]

        return recursiveConstructTree(
            preorder[0],
            0,
            rootIdx - 1,
            rootIdx + 1,
            length - 1,
        )
        