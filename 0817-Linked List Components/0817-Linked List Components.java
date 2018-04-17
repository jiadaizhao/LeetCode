/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        Set<Integer> table = new HashSet<>();
        for (int i : G) {
            table.add(i);
        }
        ListNode curr = head;
        int count = 0;
        while (curr != null) {
            if (table.contains(curr.val) && (curr.next == null || !table.contains(curr.next.val))) {
                ++count;
            }
            curr = curr.next;
        }
        return count;
    }
}
