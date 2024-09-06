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
    public ListNode modifiedList(int[] nums, ListNode head) {
        int n=nums.length;
        Map<Integer,Integer>map=new HashMap<>();
        for(int i=0;i<n;i++){
            map.put(nums[i],1);
        }
        ListNode newHead=null;
        ListNode temp=head;
        ListNode prev=null;
        while(temp!=null){
            int val=temp.val;
            if(!map.containsKey(val)){
                if(newHead==null){
                    newHead=temp;
                    prev=temp;
                }
                else{
                    prev.next=temp;
                    prev=prev.next;
                }
            }
            temp=temp.next;
        }
        if(prev!=null){
            prev.next=null;
        }
        return newHead;
    }
}