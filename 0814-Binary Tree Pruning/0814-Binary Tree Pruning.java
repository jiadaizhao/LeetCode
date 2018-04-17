/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode pruneTree(TreeNode root) {
        return contain1(root) ? root : null;
    }

    private boolean contain1(TreeNode root) {
        if (root == null) {
            return false;
        }
        boolean left = contain1(root.left);
        boolean right = contain1(root.right);
        if (!left) {
            root.left = null;
        }
        if (!right) {
            root.right = null;
        }
        return left || right || root.val == 1;
    }
}
