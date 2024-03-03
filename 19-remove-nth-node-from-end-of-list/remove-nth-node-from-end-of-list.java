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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode revnode=reverse(head);
        ListNode remnode=remove(revnode,n);
        return reverse(remnode);
    }

    public ListNode reverse(ListNode head){
        ListNode prev=null;
        ListNode next=null;
        ListNode curr=head;

        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode remove(ListNode head,int n){
        ListNode temp=head;
        if(n==1){
            return head.next;
        }
        int cnt=1;
        while(temp!=null){
            if(cnt==n-1){
                temp.next=temp.next.next;
                break;
            }
            cnt++;
            temp=temp.next;
        }
        return head;
    }
}