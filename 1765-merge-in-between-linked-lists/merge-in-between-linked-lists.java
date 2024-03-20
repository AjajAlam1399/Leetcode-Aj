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
        ListNode[] h1=findNode(list1,a,b);
        ListNode temp=list2;
        while(temp.next!=null){
            temp=temp.next;
        }
        temp.next=h1[1].next;
        h1[0].next=list2;
        return list1;
    }
    ListNode[] findNode(ListNode head,int a,int b){
        ListNode temp=head;
        ListNode[]ans=new ListNode[2];
        ans[0]=temp;
        int cnt1=0;
        int cnt2=0;
        while(cnt1<a ||cnt2<b ){
            temp=temp.next;
            cnt1++;
            cnt2++;
            if(cnt1==a-1){
                ans[0]=temp;
            }
            
        }
        ans[1]=temp;
        return ans;
    }
}