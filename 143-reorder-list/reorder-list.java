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
    public void reorderList(ListNode head) {
        if(head==null || head.next==null){
            return;
        }
        ListNode mid=head;
        ListNode fast=head;
        ListNode slow=head;

        while(fast!=null && fast.next!=null){
            mid=slow;
            slow=slow.next;
            fast=fast.next.next;
        }
        mid.next=null;
        ListNode tailHead=reverse(slow);
        ListNode newHead=null;
        ListNode temp=null;

        while(head!=null || tailHead!=null){
            if(head!=null){
                if(newHead==null){
                    newHead=head;
                    temp=head;
                }
                else{
                    temp.next=head;
                    temp=temp.next;
                }
                head=head.next;
            }
            if(tailHead!=null){
                temp.next=tailHead;
                temp=temp.next;
                tailHead=tailHead.next;
            }
        }
        head=newHead;
        return ;
    }

    ListNode reverse(ListNode head){
        if(head==null || head.next==null){
            return head;
        }
        ListNode newHead=reverse(head.next);
        head.next.next=head;
        head.next=null;
        return newHead;
    }
}