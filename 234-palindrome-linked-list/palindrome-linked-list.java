/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode mid=head;
        ListNode fast=head;
        ListNode prev=head;

        while(fast!=null && fast.next!=null){
            prev=mid;
            mid=mid.next;
            fast=fast.next.next;
        }
        prev.next=null;
        ListNode tailHead=reverse(mid);

        while(head!=null &&tailHead!=null){
            if(Integer.compare(head.val,tailHead.val)!=0){
                return false;
            }
            head=head.next;
            tailHead=tailHead.next;
        }
        return true;
    }

    ListNode reverse(ListNode head){
        ListNode prev=null;
        ListNode curr=head;
        ListNode next;

        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }

}