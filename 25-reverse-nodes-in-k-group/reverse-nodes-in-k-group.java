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
    int findSize(ListNode node){
        ListNode temp = node;
        int cnt=0;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }
        return cnt;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        int len = findSize(head);
        return fun(head,len,k);
    }
    ListNode fun(ListNode head , int len , int k){

        ListNode curr=head;
        ListNode next;
        ListNode prev=null;

        for(int i=0;i<k;i++){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        int rem=len-k;
        // System.out.println(rem);
        if(rem>k || rem==k){
            head.next=fun(curr,rem,k);
        }
        else if(rem<k){
            head.next=curr;
        }
        return prev;
    }
}