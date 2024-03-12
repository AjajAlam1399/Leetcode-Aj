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
    public ListNode removeZeroSumSublists(ListNode head) {
        Map<Integer,ListNode>map=new HashMap<>();
        ListNode newHead=head;
        ListNode temp=head;
        map.put(0,head);
        int sum=0;
        boolean flag=false;
        while(temp!=null){
            sum+=temp.val;
             if(map.containsKey(sum)){
                flag=true;
                if(sum==0){
                    newHead=temp.next;
                    break;
                }
                map.get(sum).next=temp.next;
                break;
            }
            map.put(sum,temp);
            temp=temp.next;
        }
        return flag==true?removeZeroSumSublists(newHead):newHead;
    }
}