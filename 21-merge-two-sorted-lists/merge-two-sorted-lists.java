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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode head = null;
        ListNode curr=null;
        ListNode head1=list1;
        ListNode head2=list2;

        while(head1!=null && head2!=null){
            if(head1.val<=head2.val){
                if(head==null){
                    head=head1;
                    curr=head1;
                }
                else{
                    curr.next=head1;
                    curr=curr.next;
                }
                head1=head1.next;
            }
            else{
                if(head==null){
                    head=head2;
                    curr=head2;
                }
                else{
                    curr.next=head2;
                    curr=curr.next;
                }
                head2=head2.next;
            }
        }
        if(head1!=null){
            if(head==null){
                head=head1;
            }
            else{
                curr.next=head1;
                curr=curr.next;
            }
        }

        if(head2!=null){
            if(head==null){
                head=head2;
            }
            else{
                curr.next=head2;
                curr=curr.next;
            }
        }

        return head;
    }
}