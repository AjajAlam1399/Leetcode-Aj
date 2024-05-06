/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* newHead=reverse(head);
        int currMax=INT_MIN;

        ListNode* curr=newHead;
        ListNode* prev=NULL;

        while(curr){
            if(curr->val>=currMax){
                if(!prev){
                    prev=curr;
                }
                else{
                    prev->next=curr;
                    prev=prev->next;
                }
            }
            currMax=max(currMax,curr->val);
            curr=curr->next;
        }
        if(prev)prev->next=NULL;
        return reverse(newHead);
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next;

        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};