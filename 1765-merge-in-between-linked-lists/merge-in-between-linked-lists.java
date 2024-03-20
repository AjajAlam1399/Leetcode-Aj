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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode h1=findNode(list1,a-1);
        ListNode t1=findNode(list1,b-1);
        ListNode temp=list2;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=t1.next.next;
        h1.next=list2;
        return list1;
    }
    ListNode findNode( ListNode head,int a){
        ListNode temp=head;
        int cnt=0;
        while(cnt<a){
            temp=temp.next;
            cnt++;
        }
        return temp;
    }
}