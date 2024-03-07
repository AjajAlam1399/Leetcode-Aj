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
    public ListNode middleNode(ListNode head) {
        int len=size(head);
        ListNode ans=null;
        if(len%2==0){
            ans=middle(head,len/2+1);
        }
        else{
            ans=middle(head,(len+1)/2);
        }
        return ans;
    }
    int size(ListNode head){
        int cnt=0;
        ListNode temp=head;
        while(temp!=null){
            cnt++;
            temp=temp.next;
        }
        return cnt;
    }

    ListNode middle(ListNode head,int node){
        int cnt=1;
        ListNode temp=head;
        while(cnt<node){
            temp=temp.next;
            cnt++;
        }
        return temp;
    }
}